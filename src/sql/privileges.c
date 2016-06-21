/**
@file privileges.c Provides functions for privileges
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public Licens
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */
#include "privileges.h"

/**
 * @author Kristina Takač.
 * @brief  Function which inserts user in table AK_user
 * @param *username username of user to be added
 * @param password password of user to be added
 * @return user_id
 */
int AK_user_add(char *username, int *password, int set_id) {

    char *tblName = "AK_user";
    AK_PRO;
    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    
    int user_id = AK_get_id();
    if (set_id != 0) user_id = set_id;
    Ak_Insert_New_Element(TYPE_INT, &user_id, tblName, "obj_id", row_root);
    Ak_Insert_New_Element(TYPE_VARCHAR, username, tblName, "username", row_root);
    Ak_Insert_New_Element(TYPE_INT, &password, tblName, "password", row_root);
    Ak_insert_row(row_root);
    AK_EPI;
    return user_id;
}

/**
 * @author Kristina Takač.
 * @brief  Function which gets user id
 * @param *username username of user whose id we are looking for
 * @return user_id, otherwise EXIT_ERROR
 */
int AK_user_get_id(char *username) {
    int i = 0;
    
    struct list_node *row;
    AK_PRO;

    while ((row = (struct list_node *) AK_get_row(i, "AK_user")) != NULL) {
	struct list_node *elem_in_strcmp = Ak_GetNth_L2(2,row);
        if (strcmp(elem_in_strcmp->data, username) == 0) {
            i = (int) * row->next->data;
            AK_free(row);
            AK_EPI;
            return i;
        }
        i++;
    }
    AK_free(row);
    AK_EPI;
    return EXIT_ERROR;
}

/**
 * @author Ljubo Barać
 * @brief Function removes the user.
 * @param name Name of the user to be removed
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_user_remove_by_name(char *name) {
    AK_PRO;

    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    Ak_Insert_New_Element_For_Update(TYPE_VARCHAR, name, "AK_user", "username", row_root, 1);
    int result = Ak_delete_row(row_root);
    AK_EPI;
    return result;
}

/**
 * @author Ljubo Barać, upadate by Lidija Lastavec
 * @brief Function renames the user.
 * @param old_name Name of the user to be renamed
 * @param new_name New name of the user
 * @param password Password of the user to be renamed (should be provided)
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_user_rename(char *old_name, char *new_name, int *password) {
    AK_PRO;
    int result = 0;
    int user_id = AK_user_get_id(old_name);

    
    result = AK_user_remove_by_name(old_name);
    result = AK_user_add(new_name, password, user_id);
    AK_EPI;
    return result;

}

/**
 * @author Kristina Takač, edited by Ljubo Barać
 * @brief Function that AK_group_add
 * @param *name name of group to be added
 * @param set_id non default id to be passed
 * @return id of group                                                      
 */
int AK_group_add(char *name, int set_id) {
    char *tblName = "AK_group";
    AK_PRO;

    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    int group_id = AK_get_id();
    if (set_id != 0) group_id = set_id;
    Ak_Insert_New_Element(TYPE_INT, &group_id, tblName, "obj_id", row_root);
    Ak_Insert_New_Element(TYPE_VARCHAR, name, tblName, "name", row_root);
    Ak_insert_row(row_root);
    AK_EPI;
    return group_id;
}

/**
 * @author Kristina Takač.
 * @brief Function that gets id of group with given name
 * @param *name name of group whose id we are looking for
 * @return id of group, otherwise EXIT_ERROR                                                      
 */
int AK_group_get_id(char *name) {
    int i = 0;

    struct list_node *row;
    AK_PRO;

    while ((row = (struct list_node *) AK_get_row(i, "AK_group")) != NULL) {
	struct list_node *elem_in_strcmp = Ak_GetNth_L2(2,row);
        if (strcmp(elem_in_strcmp->data, name) == 0) {
            i = (int) * row->next->data;
            AK_free(row);
            return i;
        }
        i++;
    }
    AK_free(row);
    AK_EPI;
    return EXIT_ERROR;
}

/**
 * @author Ljubo Barać
 * @brief Function removes the group.
 * @param name Name of the group to be removed
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_group_remove_by_name(char *name) {
    AK_PRO;
	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    Ak_Insert_New_Element_For_Update(TYPE_VARCHAR, name, "AK_group", "name", row_root, 1);
    int result = Ak_delete_row(row_root);
    AK_EPI;
    return result;
}

/**
 * @author Ljubo Barać, update by Lidija Lastavec
 * @brief Function renames the group.
 * @param old_name Name of the group to be renamed
 * @param new_name New name of the group
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_group_rename(char *old_name, char *new_name) {
    AK_PRO;
  
    int result = 0;
    int view_id = AK_group_get_id(old_name);

    
    result = AK_group_remove_by_name(old_name);
    result = AK_group_add(new_name, view_id);
    AK_EPI;
    return result;
}

/**
 * @author Kristina Takač, updated by Mario Peroković, inserting user id instead of username in AK_user_right
 * @brief Function that grants privilege to user
 * @param *username username of user to whom we want to grant privilege
 * @param *table name of table on which privilege will be granted to user
 * @param *right type of privilege which will be granted to user on given table
 * @return privilege_id or EXIT_ERROR if table or user aren't correct
 */
int AK_grant_privilege_user(char *username, char *table, char *right) {
    int privilege_id, table_id;
    AK_PRO;
    table_id = AK_get_table_obj_id(table);
    int user_id = AK_user_get_id(username);

    if (table_id == -1 || user_id == -1) {
	AK_EPI;
        return EXIT_ERROR;
    }

    if (strcmp(right, "ALL") == 0) {
        char rights[100];
        strcpy(&rights[0], "UPDATE\0");
        strcpy(&rights[10], "DELETE\0");
        strcpy(&rights[20], "INSERT\0");
        strcpy(&rights[30], "SELECT\0");
        int i;
        for (i = 0; i < 4; i++) {

	    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
            Ak_Init_L3(&row_root);
            privilege_id = AK_get_id();

            Ak_Insert_New_Element(TYPE_INT, &privilege_id, "AK_user_right", "obj_id", row_root);
            Ak_Insert_New_Element(TYPE_INT, &user_id, "AK_user_right", "user_id", row_root);
            Ak_Insert_New_Element(TYPE_INT, &table_id, "AK_user_right", "artifact_id", row_root);
            Ak_Insert_New_Element(TYPE_VARCHAR, &rights[i * 10], "AK_user_right", "right_type", row_root);
            Ak_insert_row(row_root);

            AK_free(row_root);
        }
    } else {

	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
        Ak_Init_L3(&row_root);

        privilege_id = AK_get_id();
        Ak_Insert_New_Element(TYPE_INT, &privilege_id, "AK_user_right", "obj_id", row_root);
        Ak_Insert_New_Element(TYPE_INT, &user_id, "AK_user_right", "user_id", row_root);
        Ak_Insert_New_Element(TYPE_INT, &table_id, "AK_user_right", "artifact_id", row_root);
        Ak_Insert_New_Element(TYPE_VARCHAR, right, "AK_user_right", "right_type", row_root);
        Ak_insert_row(row_root);
        AK_free(row_root);
    }
    AK_EPI;
    return privilege_id;
}

/**
 * @author Kristina Takač, updated by Mario Peroković - added comparing by table id, and use of user_id in AK_user_right
 * @brief Function that revokes privilege from user on given table
 * @param *username username of user to whom we want to grant privilege
 * @param *table name of table on which privilege will be revoked from user
 * @param *right type of privilege which will be revoked from user on given table
 * @return EXIT_SUCCESS if privilege is revoked, EXIT_ERROR if it isn't
 */
int AK_revoke_privilege_user(char *username, char *table, char *right) {
    AK_PRO;
    printf("Revoke: %s %s %s", username, table, right);
    int table_id = AK_get_table_obj_id(table);
    int user_id = AK_user_get_id(username);
    int result;
    if (strcmp(right, "ALL") == 0) {

	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
        Ak_Init_L3(&row_root);
        int i = 0;
        
        struct list_node *row;
	
	while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {
	    struct list_node *user = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
            if (((int) *user->data == user_id) && (table_id != -1) && ((int) *table->data == table_id)) {
                Ak_Insert_New_Element_For_Update(TYPE_INT, &user_id, "AK_user_right", "user_id", row_root, 1);
                result = Ak_delete_row(row_root);
            }
            i++;
            
	    Ak_DeleteAll_L3(&row_root);
            AK_free(row);
        }
    } else {
       
	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
        Ak_Init_L3(&row_root);
        int i = 0;
       
        struct list_node *row;

        while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {
	    struct list_node *user = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
	    struct list_node *right = Ak_GetNth_L2(4,row);
            if (((int) *user->data == user_id) && (table_id == (int) * table->data) && (table_id != -1) && (strcmp(right->data, right) == 0)) {
                int id = (int) * row->next->data;
                // strange, but it works! :)
                id = id + 1;
                Ak_Insert_New_Element_For_Update(TYPE_INT, &id, "AK_user_right", "obj_id", row_root, 1);
                result = Ak_delete_row(row_root);
            }//if
            i++;
            
	    Ak_DeleteAll_L3(&row_root);
            AK_free(row);
        }//while 
    }//else

    if (result == EXIT_ERROR){
	AK_EPI;
	return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Jurica Hlevnjak
 * @brief Function that revokes ALL privileges from user on ALL tables (for DROP user)
 * @param username name of user from whom we want to revoke all privileges
 * @return EXIT_SUCCESS if privilege is revoked, EXIT_ERROR if it isn't
 */
int AK_revoke_all_privileges_user(char *username) {
    AK_PRO;
    int user_id = AK_user_get_id(username);
    int result;
    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    int i = 0;
   
    struct list_node *row;
    
    while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {
  	struct list_node *user = Ak_GetNth_L2(2,row);
        if ((int) *user->data == user_id) {
            Ak_Insert_New_Element_For_Update(TYPE_INT, &user_id, "AK_user_right", "user_id", row_root, 1);
            result = Ak_delete_row(row_root);
        }
        i++;
        
	Ak_DeleteAll_L3(&row_root);
        AK_free(row);
    }

    if (result == EXIT_ERROR){
	AK_EPI;
	return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Kristina Takač.
 * @brief Function that grants privilege to given group on given table
 * @param *groupname  name of group to which we want to grant privilege
 * @param *table name of table on which privilege will be granted to user
 * @param *right type of privilege which will be granted to user on given table
 * @return privilege_id or EXIT_ERROR if table or user aren't correct
 */
int AK_grant_privilege_group(char *groupname, char *table, char *right) {
    int privilege_id, table_id, group_id;
    AK_PRO;
    table_id = AK_get_table_obj_id(table);
    group_id = AK_group_get_id(groupname);

    if (table_id == -1 || group_id == -1) {
	AK_EPI;
        return EXIT_ERROR;
    }

    if (strcmp(right, "ALL") == 0) {
        char rights[100];
        strcpy(&rights[0], "UPDATE\0");
        strcpy(&rights[10], "DELETE\0");
        strcpy(&rights[20], "INSERT\0");
        strcpy(&rights[30], "SELECT\0");
        int i;
        for (i = 0; i < 4; i++) {
          
	    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
	    Ak_Init_L3(&row_root);
            privilege_id = AK_get_id();

            Ak_Insert_New_Element(TYPE_INT, &privilege_id, "AK_group_right", "obj_id", row_root);
            Ak_Insert_New_Element(TYPE_INT, &group_id, "AK_group_right", "group_id", row_root);
            Ak_Insert_New_Element(TYPE_INT, &table_id, "AK_group_right", "artifact_id", row_root);
            Ak_Insert_New_Element(TYPE_VARCHAR, &rights[i * 10], "AK_group_right", "right_type", row_root);
            Ak_insert_row(row_root);

            AK_free(row_root);
        }
    } else {
    
	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
	Ak_Init_L3(&row_root);


        privilege_id = AK_get_id();
        Ak_Insert_New_Element(TYPE_INT, &privilege_id, "AK_group_right", "obj_id", row_root);
        Ak_Insert_New_Element(TYPE_INT, &group_id, "AK_group_right", "group_id", row_root);
        Ak_Insert_New_Element(TYPE_INT, &table_id, "AK_group_right", "artifact_id", row_root);
        Ak_Insert_New_Element(TYPE_VARCHAR, right, "AK_group_right", "right_type", row_root);
        Ak_insert_row(row_root);
        AK_free(row_root);
    }

    AK_EPI;
    return privilege_id;
}

/**
 * @author Kristina Takač, updated by Mario Peroković - added comparing by table id
 * @brief Function that revokes privilege from group on given table 
 * @param *grounamep name of group which user belongs to
 * @param *table name of table on which privilege will be granted to group
 * @param *right type of privilege which will be granted to group on given table
 * @return EXIT_SUCCESS if privilege is revoked, EXIT_ERROR if it isn't
 */
int AK_revoke_privilege_group(char *groupname, char *table, char *right) {
    int table_id, group_id;
    AK_PRO;
    group_id = AK_group_get_id(groupname);
    table_id = AK_get_table_obj_id(table);
    int result;

    if (strcmp(right, "ALL") == 0) {
        printf("Revoke  %s %s %s", groupname, table, right);
   
	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
	Ak_Init_L3(&row_root);
        int i = 0;
       
        struct list_node *row;
	
	while ((row = (struct list_node *) AK_get_row(i, "AK_group_right")) != NULL) {
	    struct list_node *group = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
            if ((int) * group->data == group_id && (int) * table->data == table_id) {
                Ak_Insert_New_Element_For_Update(TYPE_INT, &group_id, "AK_group_right", "group_id", row_root, 1);
                result = Ak_delete_row(row_root);
            }
            i++;
            
	    Ak_DeleteAll_L3(&row_root);
            AK_free(row);
        }
    } else {
        
	struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
	Ak_Init_L3(&row_root);
        int i = 0;
        
        struct list_node *row;
	
	while ((row = (struct list_node *) AK_get_row(i, "AK_group_right")) != NULL) {
	    struct list_node *group = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
	    struct list_node *right = Ak_GetNth_L2(4,row);
            if (((int) * group->data == group_id) && (table_id == (int) * table->data) && (strcmp(right->data, right))) {
                int id = (int) * row->next->data;
                Ak_Insert_New_Element_For_Update(TYPE_INT, &id, "AK_group_right", "obj_id", row_root, 1);
                result = Ak_delete_row(row_root);
            }
            i++;
            
	    Ak_DeleteAll_L3(&row_root);
            AK_free(row);
        }
    }

    if (result == EXIT_ERROR){
	AK_EPI;
	return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Jurica Hlevnjak
 * @brief Function that revokes ALL privileges from group on ALL tables (needed for DROP group)
 * @param groupname name of group from which we want to revoke all privileges
 * @return EXIT_SUCCESS if privilege is revoked, EXIT_ERROR if it isn't
 */
int AK_revoke_all_privileges_group(char *groupname) {
    AK_PRO;
    int group_id = AK_group_get_id(groupname);
    int result;
    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);
    int i = 0;
    
    struct list_node *row;
    
    while ((row = (struct list_node *) AK_get_row(i, "AK_group_right")) != NULL) {
    	struct list_node *group = Ak_GetNth_L2(2,row);
        if ((int) *group->data == group_id) {
            Ak_Insert_New_Element_For_Update(TYPE_INT, &group_id, "AK_group_right", "group_id", row_root, 1);
            result = Ak_delete_row(row_root);
        }
        i++;
        
	Ak_DeleteAll_L3(&row_root);
        AK_free(row);
    }

    if (result == EXIT_ERROR){
	AK_EPI;
	return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Kristina Takač, updated by Mario Peroković, added verifying the existence of user in the group, updated by Maja Vračan 
 * @brief Function that puts user in given group
 * @param *user username of user which will be put in group
 * @param *group name of group in which user will be put
 * @return EXIT_SUCCESS or EXIT_ERROR if user is already in the group
 */
int AK_add_user_to_group(char *user, char *group) {
    AK_PRO;
    int user_id = AK_user_get_id(user);
    int group_id = AK_group_get_id(group);
	
    //if group doesn't exist
    if(group_id == -1){
        AK_EPI;
        return EXIT_ERROR;
    }    

    int i = 0;
    
    struct list_node *row;
    
    while ((row = (struct list_node *) AK_get_row(i, "AK_user_group")) != NULL) {
    
        // if user is already in group, return error
        if (user_id == (int) *row->next->data) {
	    AK_EPI;
            return EXIT_ERROR;
        }
        i++;
    }

    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);

    Ak_Insert_New_Element(TYPE_INT, &user_id, "AK_user_group", "user_id", row_root);
    Ak_Insert_New_Element(TYPE_INT, &group_id, "AK_user_group", "group_id", row_root);
    Ak_insert_row(row_root);

    AK_free(row_root);

    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Jurica Hlevnjak, update by Lidija Lastavec
 * @brief Function removes user from all groups. Used for DROP user.
 * @param user name of user
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_remove_user_from_all_groups(char *user) {
    AK_PRO;
    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);

    int user_id = AK_user_get_id(user);
    int i = 0;
    int result;
    
    struct list_node *row;
    
    while ((row = (struct list_node *) AK_get_row(i, "AK_user_group")) != NULL) {
    	struct list_node *user = Ak_GetNth_L2(1,row);
        if (user_id == (int) *user->data) {
            Ak_Insert_New_Element_For_Update(TYPE_INT, &user_id, "AK_user_group", "user_id", row_root, 1);
            result = Ak_delete_row(row_root);
            if (result == EXIT_ERROR){
			printf("User '%s' is NOT in any group!\n", user);
		AK_EPI;
		return EXIT_ERROR;
	    }
        }
        i++;

	Ak_DeleteAll_L3(&row_root);
        AK_free(row);
    }

    //if (result == EXIT_ERROR) return EXIT_ERROR;
    printf("User '%s' is removed from all groups!\n", user);
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Jurica Hlevnjak, update by Lidija Lastavec
 * @brief Function removes all users from group. Used for DROP group.
 * @param group name of group
 * @return EXIT_SUCCESS or EXIT_ERROR
 */
int AK_remove_all_users_from_group(char *group) {
    AK_PRO;
    
    struct list_node *row_root = (struct list_node *) AK_malloc(sizeof (struct list_node));
    Ak_Init_L3(&row_root);

    int group_id = AK_group_get_id(group);
    int i = 0;
    int result;
    
    struct list_node *row;
    
    while ((row = (struct list_node *) AK_get_row(i, "AK_user_group")) != NULL) {
    	struct list_node *group = Ak_GetNth_L2(2,row);
        if (group_id == (int) *group->data) {
            Ak_Insert_New_Element_For_Update(TYPE_INT, &group_id, "AK_user_group", "group_id", row_root, 1);
            result = Ak_delete_row(row_root);
        
        }
        i++;
        if (result == EXIT_ERROR){
		printf("Group '%s' has NOT any user!\n", group);
		AK_EPI;
		return EXIT_ERROR;
	    }
        
	Ak_DeleteAll_L3(&row_root);
        AK_free(row);
    }

    // if (result == EXIT_ERROR) return EXIT_ERROR;
    printf("Users deleted from group '%s'!\n", group);
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Kristina Takač.
 * @brief Function that checks whether given user has right for given operation on given table
 * @param *user username for which we want check privileges
 * @param *table name of table for which we want to check whether user has right on
 * @param *privilege privilege for which we want to check whether user has right for
 * @return EXIT_SUCCESS if user has right, EXIT_ERROR if user has no right
 */
int AK_check_privilege(char *username, char *table, char *privilege) {
    AK_PRO;
    int user_id = AK_user_get_id(username);
    int table_id = AK_get_table_obj_id(table);
    int i = 0;
    int number_of_groups = 0;
    int has_right = 0;
    int groups[100];
    
    struct list_node *row;
    
    if (strcmp(privilege, "ALL") == 0) {
        int checking_privileges[4] = {0, 0, 0, 0};
        char found_privilege[10];
        while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {
	    
	    struct list_node *username = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
            if ((strcmp(username->data, username) == 0) && (table_id == (int) * table->data)) {
		struct list_node *privilege_elem = Ak_GetNth_L2(4,row);
                strcpy(found_privilege, privilege_elem->data);
                if (strcmp(found_privilege, "UPDATE") == 0)
                    checking_privileges[0] = 1;
                if (strcmp(found_privilege, "DELETE") == 0)
                    checking_privileges[1] = 1;
                if (strcmp(found_privilege, "INSERT") == 0)
                    checking_privileges[2] = 1;
                if (strcmp(found_privilege, "SELECT") == 0)
                    checking_privileges[3] = 1;
            }
            i++;
            AK_free(row);
        }
        for (i = 0; i < 4; i++) {
            if (checking_privileges[i] == 1) {
                has_right = 1;
            } else {
                has_right = 0;
                break;
            }
        }
        if (has_right == 1) {
            printf("User %s has right to %s on %s", username, privilege, table);
	    AK_EPI;
            return EXIT_SUCCESS;
        }
        i = 0;
        while ((row = (struct list_node *) AK_get_row(i, "AK_user_group")) != NULL) {
            while ((row = (AK_list *) AK_get_row(i, "AK_user_group")) != NULL) {
                struct list_node *user = Ak_GetNth_L2(1,row);
                if (user_id == (int) * user->data) {
                    struct list_node *group = Ak_GetNth_L2(2,row);
                    groups[number_of_groups] = (int) * group->data;
                    number_of_groups++;
                }
                i++;
                AK_free(row);
            }
            // set "flags" to 0
            checking_privileges[0] = 0;
            checking_privileges[1] = 0;
            checking_privileges[2] = 0;
            checking_privileges[3] = 0;
            for (i = 0; i < number_of_groups; i++) {
                int j = 0;
                while ((row = (AK_list *) AK_get_row(j, "AK_group_right")) != NULL) {
                    struct list_node *group = Ak_GetNth_L2(2,row);
                    struct list_node *table = Ak_GetNth_L2(3,row);
                    struct list_node *privilege_elem = Ak_GetNth_L2(4,row);

                    if ((groups[i] == (int) * group->data) && (table_id == (int) * table->data)) {
                        strcpy(found_privilege, privilege_elem->data);
                        if (strcmp(found_privilege, "UPDATE") == 0)
                            checking_privileges[0] = 1;
                        if (strcmp(found_privilege, "DELETE") == 0)
                            checking_privileges[1] = 1;
                        if (strcmp(found_privilege, "INSERT") == 0)
                            checking_privileges[2] = 1;
                        if (strcmp(found_privilege, "SELECT") == 0)
                            checking_privileges[3] = 1;
                    }
                    j++;
                    AK_free(row);
                }
            }
            for (i = 0; i < 4; i++) {
                if (checking_privileges[i] == 1) {
                    has_right = 1;
                } else {
                    has_right = 0;
                    break;
                }
            }
            if (has_right == 1) {
                printf("User %s has right to %s on %s", username, privilege, table);
                AK_EPI;
                return EXIT_SUCCESS;
            }
        }
    }// if privilege is not ALL
    else {
        
	while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {  
	    struct list_node *username = Ak_GetNth_L2(2,row);
	    struct list_node *table = Ak_GetNth_L2(3,row);
	    struct list_node *privilege_elem = Ak_GetNth_L2(4,row);
            if ((strcmp(username->data, username) == 0) && (table_id == (int) * table->data) && (strcmp(privilege_elem->data, privilege) == 0)) {
                has_right = 1;
                printf("User %s has right to %s on %s", username, privilege, table);
                AK_EPI;
                return EXIT_SUCCESS;
            }
            i++;
            AK_free(row);
        }
        i = 0;
        while ((row = (struct list_node *) AK_get_row(i, "AK_user_group")) != NULL) {
	    struct list_node *user = Ak_GetNth_L2(1,row);
	
            if (user_id == (int) * user->data) {
	    	struct list_node *group = Ak_GetNth_L2(2,row);
                groups[number_of_groups] = (int) * group->data;
                number_of_groups++;
            }
            i++;
            AK_free(row);
        }
        for (i = 0; i < number_of_groups; i++) {
            int j = 0;
            
	    while ((row = (struct list_node *) AK_get_row(j, "AK_group_right")) != NULL) {  
		struct list_node *groups_elem = Ak_GetNth_L2(2,row);
		struct list_node *table = Ak_GetNth_L2(3,row);
		struct list_node *privilege_elem = Ak_GetNth_L2(4,row);
                if ((groups[i] == (int) * groups_elem->data) && (table_id == (int) * table->data) && (strcmp(privilege_elem->data,privilege) == 0)) {
                    has_right = 1;
                    printf("User %s has right to %s on %s", username, privilege, table);
		    AK_EPI;
                    return EXIT_SUCCESS;
                }
                j++;
                AK_free(row);
            }
        }
    }

    printf("User %s has no right to %s on %s", username, privilege, table);
    AK_EPI;
    return EXIT_ERROR;
}

/**
 * @author Jurica Hlevnjak, updated by Lidija Lastavec
 * @brief Function check if user have any privilege or belong to group. Used in drop user for restriction.
 * @param user name of user
 * @return EXIT_ERROR or EXIT_SUCCESS
 */
int AK_check_user_privilege(char *user) {
    AK_PRO;
    int user_id = AK_user_get_id(user);
    int i = 0;
    
    struct list_node *row;
    int privilege = 0;

    while ((row = (struct list_node *) AK_get_row(i, "AK_user_right")) != NULL) {
    	struct list_node *user = Ak_GetNth_L2(2,row);
        if ((int) *user->data == user_id) {
            privilege = 1;
        AK_EPI;
            return EXIT_SUCCESS;
        }
        i++;
        AK_free(row);
    }
    int j = 0;
    while ((row = (struct list_node *) AK_get_row(j, "AK_user_group")) != NULL) {
    	struct list_node *user = Ak_GetNth_L2(1,row);
        if ((int) *user->data == user_id) {
            privilege = 1;
            printf("User %s has privilage!", user);
	    AK_EPI;
            return EXIT_SUCCESS;
        }
        j++;
        AK_free(row);
    }
    if (privilege == 0) {
		printf("User %s has NOT any privilage!", user);
		AK_EPI;
        return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Jurica Hlevnjak, updated by Lidija Lastavec
 * @brief Function check if group have any privilege or user. Used in drop group for restriction.
 * @param group name of group
 * @return EXIT_ERROR or EXIT_SUCCESS
 */
int AK_check_group_privilege(char *group) {
    AK_PRO;
    int group_id = AK_group_get_id(group);
    int i = 0;
    
    struct list_node *row;
    int privilege = 0;

    while ((row = (struct list_node *) AK_get_row(i, "AK_group_right")) != NULL) {
    	struct list_node *group = Ak_GetNth_L2(2,row);
        if ((int) *group->data == group_id) {
            privilege = 1;
        printf("Group %s has privilage!", group);  
	    AK_EPI;
            return EXIT_SUCCESS;
        }
        i++;
        AK_free(row);
    }
    int j = 0;
    while ((row = (struct list_node *) AK_get_row(j, "AK_user_group")) != NULL) {
    	struct list_node *group = Ak_GetNth_L2(2,row);
        if ((int) *group->data == group_id) {
            privilege = 1;
	    AK_EPI;
            return EXIT_SUCCESS;
        }
        j++;
        AK_free(row);
    }
    if (privilege == 0) {
		printf("Group %s has NOT any privilage!", group);  
		AK_EPI;
        return EXIT_ERROR;
    }
    AK_EPI;
    return EXIT_SUCCESS;
}

/**
 * @author Kristina Takač, updated by Tomislav Ilisevic, updated by Lidija Lastavec
 * @brief Function that tests functions above for privileges, 
 * @return no return value                                                     
 */
void AK_privileges_test() {
    AK_PRO;
    
    printf("\nThis is PRIVILEGES test!\n\n");
    
    int successfull[18] = {0};
    
    printf("1. Test for function AK_user_add - inserts users in table AK_user!\n");
	printf("\n   Test data: testing 123; kitakac 321; mrvasedam 569; swallow 666; testtest 777; protest 888 \n   Result: ");
	if(
		AK_user_add("testing", (int*) 123, NEW_ID) == EXIT_ERROR){
		printf("Test 1. - Fail!\n");
				
	} else {
		printf("Test 1. - Pass!\n");
		successfull[0]=1;
	}
	// more users for testing
	    AK_user_add("kritakac", (int*) 321, NEW_ID);
		AK_user_add("mrvasedam", (int*) 569, NEW_ID);
		AK_user_add("swallow", (int*) 666, NEW_ID);   
		AK_user_add("testtest", (int*) 777, NEW_ID);  
		AK_user_add("protest", (int*) 888, NEW_ID);  
        AK_print_table("AK_user");

	printf("\n\n2. Test for function AK_user_rename - renames the user in table AK_user!\n");
	printf("\n   Test data: from user-testing to user-test\n   Result: ");
	if(
		AK_user_rename("testing", "test", (int*) 123) == EXIT_ERROR){
		printf("Test 2. - Fail!\n");
				
	} else {
		printf("Test 2. - Pass!\n");
		successfull[1]=1;
	}
       AK_print_table("AK_user");
       
       
	printf("\n\n3. Test for function AK_user_remove_by_name - removes the user by name from table AK_user!\n");
	printf("\n   Test data: removing user - swallow\n   Result: ");
	if(
		 AK_user_remove_by_name("swallow") == EXIT_ERROR){
		printf("Test 3. - Fail!\n");
				
	} else {
		printf("Test 3. - Pass!\n");
		successfull[2]=1;
	}
    AK_print_table("AK_user");

    printf("\n\n4. Test for function AK_group_add - add group in table AK_group!\n");
	printf("\n   Test data: group1, group2, group3, groupL, group11, group12\n   Result: ");
	if(
		 AK_group_add("group1", NEW_ID) == EXIT_ERROR){
		printf("Test 4. - Fail!\n");
				
	} else {
		printf("Test 4. - Pass!\n");
		successfull[3]=1;
	}
    //more groups for testing
    AK_group_add("group2", NEW_ID);
    AK_group_add("group3", NEW_ID);
    AK_group_add("groupL", NEW_ID);
    AK_group_add("group11", NEW_ID);
    AK_group_add("group12", NEW_ID);
    AK_print_table("AK_group");
    
    printf("\n\n5. Test for function AK_group_rename - renames the group!\n");
	printf("\n   Test data: group1 to group5, group2 to group4\n   Result: ");
	if(
		 AK_group_rename("group1", "group5") == EXIT_ERROR){
		printf("Test 5. - Fail!\n");
				
	} else {
		printf("Test 5. - Pass!\n");
		successfull[4]=1;
	}
    //more groups renaming for test
    AK_group_rename("group2", "group4");
    AK_print_table("AK_group");
    
    printf("\n\n6. Test for function AK_group_remove_by_name - remove the group by name from table AK_group!\n");
	printf("\n   Test data: groupL\n   Result: ");
	if(
		AK_group_remove_by_name("groupL") == EXIT_ERROR){
		printf("Test 6. - Fail!\n");
				
	} else {
		printf("Test 6. - Pass!\n");
		successfull[5]=1;
	}
    AK_print_table("AK_group"); 

    printf("\n\n7. Test for function AK_add_user_to_group - puts user in given group!\n");
	printf("\n   Test data:kritakac to group5; test to group5; mrvasedam to group4, testtest to group11\n   Result: ");
	if(
		AK_add_user_to_group("kritakac", "group5") == EXIT_ERROR){
		printf("Test 7. - Fail!\n");
				
	}else if(AK_add_user_to_group("kritakac", "grupa") == EXIT_ERROR){
                printf("Test 7. - Pass!\n");
                successfull[6]=1;
        }else {
		printf("Test 7. - Pass!\n");
		successfull[6]=1;
	}
    //more users to groups for testing
    AK_add_user_to_group("test", "group5");
    AK_add_user_to_group("mrvasedam", "group4");
    AK_add_user_to_group("testtest", "group11");
    AK_add_user_to_group("test","grupa");
    AK_print_table("AK_user_group");
    
	printf("\n\n8. Test for function  AK_grant_privilege_group - grants privilege to given group on given table!\n");
	printf("\n   Test data: privileges for all groups \n   Result: ");
	if(
		AK_grant_privilege_group("group4", "professor", "DELETE") == EXIT_ERROR){
		printf("Test 8. - Fail!\n");
				
	} else {
		printf("Test 8. - Pass!\n");
		successfull[7]=1;
	}
   //more privileges to groups for testing
    AK_grant_privilege_group("group5", "student", "ALL");
    AK_grant_privilege_group("group4", "student", "ALL");
    AK_grant_privilege_group("group3", "student", "UPDATE");
    AK_grant_privilege_group("group11", "student", "DELETE");
    AK_print_table("AK_group_right");
    
    printf("\n\n9. Test for function  AK_revoke_privilege_group -revokes privilege from group on given table!\n");
	printf("\n   Test data: revoke privieleg for group3 od table student \n   Result: ");
	if(
		AK_revoke_privilege_group("group3", "student", "ALL") == EXIT_ERROR){
		printf("\n   Test 9. - Fail!\n");
				
	} else {
		printf("\n   Test 9. - Pass!\n");
		successfull[8]=1;
	}
    AK_print_table("AK_group_right");
    // if tested data were for group4,student,all - test pass but revoke ALL privileges for group4 on ALL tables
    // tested by Lidija Lastavec - BUG in function AK_revoke_privilege_group 
   
    printf("\n\n10. Test for function  AK_revoke_all_privileges_group -revokes ALL privileges from group on ALL tables!\n");
	printf("\n   Test data: revoke all privieleg for group4 on all tables\n   Result: ");
	if(
		AK_revoke_all_privileges_group("group4") == EXIT_ERROR){
		printf("Test 10. - Fail!\n");
				
	} else {
		printf("Test 10. - Pass!\n");
		successfull[9]=1;
	}
     AK_print_table("AK_group_right");
	
	printf("\n\n11. Test for function AK_grant_privilege_user -grants privilege to user!\n");
	printf("\n   Test data: grant privileges for users TEST, KRITAKAC,MRVASEDAM and TESTTEST\n   Result: ");
	if(
		AK_grant_privilege_user("test", "student", "UPDATE") == EXIT_ERROR){
		printf("Test 11. - Fail!\n");
				
	} else {
		printf("Test 11. - Pass!\n");
		successfull[10]=1;
	}	
	//more privileges for user kritakac     
    AK_grant_privilege_user("kritakac", "student", "DELETE");
    AK_grant_privilege_user("kritakac", "professor", "SELECT");
    AK_grant_privilege_user("kritakac", "employee", "ALL");
    AK_grant_privilege_user("mrvasedam", "student", "UPDATE");
    AK_grant_privilege_user("testtest", "employee", "SELECT");
    AK_print_table("AK_user_right");
    // in table AK_user_right missing user_id!!
    
    printf("\n\n12. Test for function AK_revoke_privilege_user -revokes privilege from user on given table!\n");
	printf("\n   Test data: revoke privilages for user test on table student\n   Result: ");
	if(
		AK_revoke_privilege_user("test", "student", "UPDATE") == EXIT_ERROR){
		printf("\n   Test 12. - Fail!\n");
				
	} else {
		printf("\n   Test 12. - Pass!\n");
		successfull[11]=1;
	} 
	// test pass but didnt revoke privilages for user test - Lidija Lastavec
    AK_print_table("AK_user_right");
    
    printf("\n\n13. Test for function AK_revoke_all_privileges_user -revokes ALL privileges from user on ALL tables!\n");
	printf("\n   Test data: revoke privilages for user kritakac on all tables\n   Result: ");
	if(
		AK_revoke_all_privileges_user("kritakac") == EXIT_ERROR){
		printf("\n   Test 13. - Fail!\n");
				
	} else {
		printf("\n   Test 13. - Pass!\n");
		successfull[12]=1;
	} 
	AK_print_table("AK_user_right");
	// test pass but didnt revoke ALL privilages for user kritakac - Lidija Lastavec
    
    printf("\n\n14. Test for function AK_check_privilege -checks whether given user has right for given operation!\n");
	printf("\n   Test data: check if user TEST has right UPDATE on table STUDENT\n   Result: ");
	if(
		AK_check_privilege("test", "student", "UPDATE") == EXIT_ERROR){
		printf("\n   Test 14. - Fail!\n");
				
	} else {
		printf("\n   Test 14. - Pass!\n");
		successfull[13]=1;
	}
	// test for NO answer - test PASS!
	printf("\n   Test data: check if user TEST has right SELECT on table PROFESSOR\n   Result: ");
	if(
		AK_check_privilege("test", "professor", "SELECT") == EXIT_ERROR){
		printf("\n   Test 14. - Pass!\n");		
	} else {
		printf("\n   Test 14. - Fail!\n");
	}
    AK_print_table("AK_user_right");
    
	printf("\n\n15. Test for function AK_check_group_privilege - check if exist the privilege or not!\n");
	printf("\n   Test data: group5-group_id 114 has privileges..\n   Result: ");
	if(AK_check_group_privilege("group5") == EXIT_SUCCESS) {
		printf("\n   Test 15. - Pass!\n");
		successfull[14]=1;
	} else {
		printf("\n   Test 15. - Fail!\n");
	}
	// test for NO answer - test PASS!
	printf("\n   Test data: group3-group_id 116-without privileges..\n   Result: ");
	if(AK_check_group_privilege("group3") == EXIT_ERROR) {
		printf("\n   Test 15. - Pass!\n");
	} else {
		printf("\n   Test 15. - Fail!\n");
	}
	AK_print_table("AK_group_right");
	
	printf("\n\n16. Test for function AK_check_user_privilege -check if user have any privilege or belong to group!\n");
	printf("\n   Test data: check if user TEST has ANY privileges\n   Result: ");
	if(
		AK_check_user_privilege("test") == EXIT_ERROR){
		printf("\n   Test 16. - Fail!\n");
				
	} else {
		printf("\n   Test 16. - Pass!\n");
		successfull[15]=1;
	}
	// test for NO answer - test PASS!
	printf("\n   Test data: check if user SWALLOW has ANY privileges\n   Result: ");
	if (
		AK_check_user_privilege("swallow") == EXIT_ERROR) {
		printf("\n   Test 16. - Pass!\n");
	} else {
		printf("\n   Test 16. - Fail!\n");
	}
	AK_print_table("AK_user_right");

	/*
	printf("\n6. Test: Group that not exist..group6..\nResult: ");
	if(AK_revoke_privilege_group("group6", "student", "ALL") == EXIT_SUCCESS) {
		printf("Group '%s' has no more privileges '%s' upon table '%s'!\n", "group6", "ALL", "student");
		successfull[5]=1;
	} else {
		printf("Error during removing privileges for group '%s'!\n", "group6");
	}
	AK_print_table("AK_group_right");
	*/

	printf("\n\n17. Test for function AK_remove_all_users_from_group - removes all users from some group\n");
	printf("\n   Test data: group5-group_id 114- with added users..\n   Result: ");
	if(AK_remove_all_users_from_group("group5") == EXIT_SUCCESS) {
		//printf("Users deleted from group '%s'!\n", "group1");
		printf("\n   Test 17. - Pass!\n");
		successfull[16]=1;
	} else {
		//printf("Error deleting user from group '%s'!\n", "group1");
		printf("\n   Test 17. - Fail!\n");
	}
		AK_print_table("AK_user_group");
	// NON existent group	
	printf("\n   Test data: group9-NONexistent-without users..\n   Result: ");
	if(AK_remove_all_users_from_group("group9") == EXIT_ERROR) {
		//printf("Users deleted from group '%s'!\n", "group3");
		//successfull[7]=1;
		printf("\n   Test 17. - Pass!\n");
	} else {
		//printf("Error deleting user from group '%s'!\n", "group3");
		printf("\n   Test 17. - Fail!\n");
		// test for non existent group -FAIL
	}
	AK_print_table("AK_user_group");
	

	printf("\n\n18. Test for function AK_remove_user_from_all_groups - removes all users from all groups\n");
	printf("\n   Test data: user in group: testtest-group11..\n   Result: ");
	
	if(AK_remove_user_from_all_groups("testtest") == EXIT_SUCCESS) {
		printf("\n   Test 18. - Pass!\n");
		successfull[17]=1;
	} 
	
	else {
		printf("\n   Test 18. - Fail!\n");
	}
	
	printf("\n   Test data: User whitout group - PROTEST..\n   Result: ");
	
	if(AK_remove_user_from_all_groups("protest") == EXIT_ERROR) {
		printf("\n   Test 18. - Pass!\n");
	} 
	
	else {
		//printf("Error deleting user '%s' from groups!\n", "testing");
		printf("\n   Test 18. - Fail!\n");
	}

	AK_print_table("AK_user_group");

	printf("\nSummary: \n");
	int num=0;
	int numFail=0;
	for(num=0;num<18;num++){
		printf("%i. Test: %s \n", (num+1),  (successfull[num]==1?"Pass":"Fail"));
		if(successfull[num]==0) numFail++;
	}

	if(numFail==0) printf("\nALL TESTS ARE PASSED! \n");
	else printf("\nThere are %i tests that failed.. \n", numFail);
    AK_EPI;
}