/**
@file hash.c Provides functions for Hash indices
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */


#include "hash.h"

/**
 Function for creation of test table
 @param tblName name of te table
 @author Mislav Čakarić
 */
void create_test_table_for_hash(char *tblName) {
    //create header
    AK_header t_header[ MAX_ATTRIBUTES ];
    AK_header* temp;

    temp = (AK_header*) AK_create_header("mbr", TYPE_INT, FREE_INT, FREE_CHAR, FREE_CHAR);
    memcpy(t_header, temp, sizeof ( AK_header));

    temp = (AK_header*) AK_create_header("firstname", TYPE_VARCHAR, FREE_INT, FREE_CHAR, FREE_CHAR);
    memcpy(t_header + 1, temp, sizeof ( AK_header));

    temp = (AK_header*) AK_create_header("lastname", TYPE_VARCHAR, FREE_INT, FREE_CHAR, FREE_CHAR);
    memcpy(t_header + 2, temp, sizeof ( AK_header));

    temp = (AK_header*) AK_create_header("year", TYPE_INT, FREE_INT, FREE_CHAR, FREE_CHAR);
    memcpy(t_header + 3, temp, sizeof ( AK_header));

    temp = (AK_header*) AK_create_header("tezina", TYPE_FLOAT, FREE_INT, FREE_CHAR, FREE_CHAR);
    memcpy(t_header + 4, temp, sizeof ( AK_header));

    memset(t_header + 5, 0, MAX_ATTRIBUTES - 5);

    //create table

    int startAddress = AK_initialize_new_segment(tblName, SEGMENT_TYPE_TABLE, t_header);

    if (startAddress != EXIT_ERROR)
        printf("\nTABLE %s CREATED!\n", tblName);

    element row_root = (element) malloc(sizeof (list));
    InitializeList(row_root);

    int mbr = 35890, year = 1999;
    float weight = 80.00;

    //insert rows in table student
    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "CHUCK", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "NORRIS", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Netko", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Netkic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Mislav", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Cakaric", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivan", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Horvat", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivo", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Marko", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Markovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivan", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivanovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Josip", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Josipovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ana", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ankovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Marina", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Marovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Mario", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Maric", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Matija", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Matkovic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivana", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Ivic", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "John", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Smith", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "William", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Brown", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "David", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Jones", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Robert", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "White", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "James", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Jones", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Jack", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Moore", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Joseph", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Harris", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Richard", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Thomas", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Daniel", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Jackson", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Martin", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Clark", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Joe", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Davis", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Paul", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Lee", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);

    mbr++;
    year++;
    weight += 0.75;
    DeleteAllElements(row_root);
    InsertNewElement(TYPE_INT, &mbr, tblName, "mbr", row_root);
    InsertNewElement(TYPE_VARCHAR, "Steve", tblName, "firstname", row_root);
    InsertNewElement(TYPE_VARCHAR, "Parker", tblName, "lastname", row_root);
    InsertNewElement(TYPE_INT, &year, tblName, "year", row_root);
    InsertNewElement(TYPE_FLOAT, &weight, tblName, "tezina", row_root);
    insert_row(row_root);


    //print table "student"
    AK_print_table(tblName);
}

/**
 Function for fetching nth element in row
 @param pos position of element in row
 @param row list of elements of row in table
 @return element of list of elements of row in table
 @author Mislav Čakarić
 */
AK_list_elem AK_get_nth_in_row(int pos, AK_list *row) {
    int i = 0;
    AK_list_elem temp_elem;

    temp_elem = FirstL(row);
    do {
        if (pos == i)
            return temp_elem;
        temp_elem = NextL(temp_elem, row);
        i++;
    } while (temp_elem);
    return NULL;
}

/**
 Function for computing a hash value from varchar or integer
 @param elem element of row for wich value is to be computed
 @return hash value
 @author Mislav Čakarić
 */
int AK_elem_hash_value(AK_list_elem elem) {
    int type = elem->type, value = 0, i = 0;
    char temp_char[MAX_VARCHAR_LENGHT];
    switch (type) {
        case TYPE_INT:
            memcpy(&value, elem->data, elem->size);
            break;
        case TYPE_VARCHAR:
            memcpy(temp_char, elem->data, elem->size);
            temp_char[ elem->size ] = '\0';
            do {
                value += (int) temp_char[i++];
            } while (temp_char[i]);
            break;
    }
    return value;
}

/**
 Function for inserting bucket to block
 @param indexName name of index
 @param data content of bucket stored in char array
 @param type type of bucket (MAIN_BUCKET or HASH_BUCKET)
 @return address structure with data where the bucket is stored
 @author Mislav Čakarić
 */
struct_add* insert_bucket_to_block(char *indexName, char *data, int type) {
    int id, size;
    struct_add *add = (struct_add*) malloc(sizeof (struct_add));
    add->addBlock = 0;
    add->indexTd = 0;

    int adr_to_write = (int) find_free_space(get_table_addresses(indexName));
    if (adr_to_write == -1)
        adr_to_write = (int) AK_init_new_extent(indexName, SEGMENT_TYPE_TABLE);
    if (adr_to_write == 0)
        return add;

    AK_block *block = (AK_block*) AK_read_block(adr_to_write);

    if (DEBUG)
        printf("insert_bucket_to_block: Position to write (tuple_dict_index) %d\n", id);

    switch (type) {
        case MAIN_BUCKET:
            size = sizeof (main_bucket);
            break;
        case HASH_BUCKET:
            size = sizeof (hash_bucket);
            break;
    }
    id = block->last_tuple_dict_id + 1;
    memcpy(&block->data[block->free_space], data, size);
    block->tuple_dict[id].address = block->free_space;
    block->free_space += size;
    block->tuple_dict[id].type = type;
    block->tuple_dict[id].size = size;
    block->last_tuple_dict_id = id;
    AK_write_block(block);

    add->addBlock = adr_to_write;
    add->indexTd = id;

    return add;
}

/**
 Function for update bucket in block
 @param add address of where the bucket is stored
 @param data content of bucket stored in char array
 @author Mislav Čakarić
 */
void update_bucket_in_block(struct_add *add, char *data) {
    AK_block *block = (AK_block*) AK_read_block(add->addBlock);
    int address = block->tuple_dict[add->indexTd].address;
    int size = block->tuple_dict[add->indexTd].size;
    memcpy(&block->data[address], data, size);
    AK_write_block(block);
}

/**
 Function for changing info of hash index
 @param indexName name of index
 @param modulo value for modulo hash function
 @param main_bucket_num number of main buckets
 @param hash_bucket_num number of hash buckets
 @author Mislav Čakarić
 */
void AK_change_hash_info(char *indexName, int modulo, int main_bucket_num, int hash_bucket_num) {
    table_addresses *hash_addresses = (table_addresses*) get_table_addresses(indexName);
    int block_add = hash_addresses->address_from[ 0 ];
    AK_block *block = (AK_block*) AK_read_block(block_add);
    hash_info *info = (hash_info*) malloc(sizeof (hash_info));
    info->modulo = modulo;
    info->main_bucket_num = main_bucket_num;
    info->hash_bucket_num = hash_bucket_num;

    memcpy(block->data, info, sizeof (hash_info));
    block->tuple_dict[0].address = 0;
    block->tuple_dict[0].type = INFO_BUCKET;
    block->tuple_dict[0].size = sizeof (hash_info);
    AK_write_block(block);
}

/**
 Function for fetching info for hash index
 @param indexName name of index
 @return info bucket with info data for hash index
 @author Mislav Čakarić
 */
hash_info* AK_get_hash_info(char *indexName) {
    table_addresses *hash_addresses = (table_addresses*) get_table_addresses(indexName);
    int block_add = hash_addresses->address_from[ 0 ];
    AK_block *block = (AK_block*) AK_read_block(block_add);
    hash_info *info = (hash_info*) malloc(sizeof (hash_info));
    memcpy(info, block->data, sizeof (hash_info));
    return info;
}

/**
 Function for fetching nth main bucket
 @param indexName name of index
 @param n number of main bucket
 @return address structure with data where the bucket is stored
 @author Mislav Čakarić
 */
struct_add* get_nth_main_bucket_add(char *indexName, int n) {
    int i = 0, j = 0, k = 0, counter = 0, end = 0;
    struct_add *add = (struct_add*) malloc(sizeof (struct_add));
    add->addBlock = 301;
    add->indexTd = 2;
    table_addresses *addresses = (table_addresses*) get_table_addresses(indexName);
    while (addresses->address_from[i]) {
        for (j = addresses->address_from[i]; j < addresses->address_to[i]; j++) {
            AK_block *temp = (AK_block*) AK_read_block(j);
            for (k = 0; k < DATA_BLOCK_SIZE; k++) {
                if (temp->tuple_dict[k].type == FREE_INT)
                    break;
                if (temp->tuple_dict[k].type == MAIN_BUCKET) {
                    if (n == counter) {
                        add->addBlock = j;
                        add->indexTd = k;
                        end = 1;
                        break;
                    }
                    counter++;
                }
            }
            if (end) break;
        }
        i++;
    }
    return add;
    free(add);
}

/**
 Function for inserting record in hash bucket
 @param indexName name of index
 @param hashValue hash value of record that is being inserted
 @param add address structure with data where the hash bucket is stored
 @author Mislav Čakarić
 */
int AK_insert_in_hash_index(char *indexName, int hashValue, struct_add *add) {
    int i, j, address, size, hash_free_space = 0;
    struct_add *main_add = (struct_add*) malloc(sizeof (struct_add));
    struct_add *hash_add = (struct_add*) malloc(sizeof (struct_add));
    main_bucket *temp_main_bucket = (main_bucket*) malloc(sizeof (main_bucket));
    hash_bucket *temp_hash_bucket = (hash_bucket*) malloc(sizeof (hash_bucket));

    table_addresses *addresses = (table_addresses*) get_table_addresses(indexName);
    if (addresses->address_from[0] == NULL)
        printf("Hash index not created yet!\n");
    else {
        char data[255];
        memset(data, 0, 255);
        hash_info *info = (hash_info*) malloc(sizeof (hash_info));
        info = AK_get_hash_info(indexName);
        if (info->main_bucket_num == 0) {
            for (i = 0; i < MAIN_BUCKET_SIZE; i++) {
                temp_main_bucket->element[i].value = i;
                memset(&temp_main_bucket->element[i].add, 0, sizeof (struct_add));
            }
            memcpy(&data, temp_main_bucket, sizeof (main_bucket));
            main_add = insert_bucket_to_block(indexName, data, MAIN_BUCKET);
            //printf("0. Block broj:%d, indexTd:%d\n", main_add->addBlock, main_add->indexTd);
            temp_hash_bucket->bucket_level = MAIN_BUCKET_SIZE;
            for (i = 0; i < HASH_BUCKET_SIZE; i++) {
                temp_hash_bucket->element[i].value = -1;
            }
            memcpy(&data, temp_hash_bucket, sizeof (hash_bucket));
            for (i = 0; i < MAIN_BUCKET_SIZE; i++) {
                hash_add = insert_bucket_to_block(indexName, data, HASH_BUCKET);
                //printf("1. Block broj:%d, indexTd:%d\n", hash_add->addBlock, hash_add->indexTd);
                memcpy(&temp_main_bucket->element[i].add, hash_add, sizeof (struct_add));
            }
            memcpy(&data, temp_main_bucket, sizeof (main_bucket));
            update_bucket_in_block(main_add, data);
            AK_change_hash_info(indexName, MAIN_BUCKET_SIZE, 1, MAIN_BUCKET_SIZE);
        }
        int hash_bucket_id = hashValue % info->modulo;
        int main_bucket_id = (int) (hash_bucket_id / MAIN_BUCKET_SIZE);

        main_add = get_nth_main_bucket_add(indexName, main_bucket_id);
        //printf("2. Block broj:%d, indexTd:%d\n", main_add->addBlock, main_add->indexTd);
        AK_block *temp_block = (AK_block*) AK_read_block(main_add->addBlock);
        address = temp_block->tuple_dict[main_add->indexTd].address;
        size = temp_block->tuple_dict[main_add->indexTd].size;
        memcpy(temp_main_bucket, &temp_block->data[address], size);

        memcpy(hash_add, &temp_main_bucket->element[hash_bucket_id % MAIN_BUCKET_SIZE].add, sizeof (struct_add));
        //printf("3. Block broj:%d, indexTd:%d\n", hash_add->addBlock, hash_add->indexTd);

        temp_block = (AK_block*) AK_read_block(hash_add->addBlock);
        address = temp_block->tuple_dict[hash_add->indexTd].address;
        size = temp_block->tuple_dict[hash_add->indexTd].size;
        memcpy(temp_hash_bucket, &temp_block->data[address], size);
        for (i = 0; i < HASH_BUCKET_SIZE; i++) {
            if (temp_hash_bucket->element[i].value == -1) {
                hash_free_space = 1;
                temp_hash_bucket->element[i].value = hashValue;
                memcpy(&temp_hash_bucket->element[i].add, add, sizeof (struct_add));
                memcpy(&data, temp_hash_bucket, sizeof (hash_bucket));
                update_bucket_in_block(hash_add, data);
                break;
            }
        }
        if (hash_free_space == 0) {
            //printf("Bucket splitting!\n");
            if (temp_hash_bucket->bucket_level == info->modulo) {
                //adding new main buckets
                for (i = 0; i < info->main_bucket_num; i++) {
                    main_add = get_nth_main_bucket_add(indexName, i);
                    AK_block *temp_block = (AK_block*) AK_read_block(main_add->addBlock);
                    address = temp_block->tuple_dict[main_add->indexTd].address;
                    size = temp_block->tuple_dict[main_add->indexTd].size;
                    memcpy(data, &temp_block->data[address], size);
                    insert_bucket_to_block(indexName, data, MAIN_BUCKET);
                }
                AK_change_hash_info(indexName, info->modulo * 2, info->main_bucket_num * 2, info->hash_bucket_num);
                info = AK_get_hash_info(indexName);
            }
            int hash_bucket_id2 = (hash_bucket_id + info->modulo / 2) % info->modulo;
            int main_bucket_id2 = (int) (hash_bucket_id2 / MAIN_BUCKET_SIZE);

            //swapping hash bucket id's
            if (hash_bucket_id2 < hash_bucket_id) {
                int temp = hash_bucket_id;
                hash_bucket_id = hash_bucket_id2;
                hash_bucket_id2 = temp;
                temp = main_bucket_id;
                main_bucket_id = main_bucket_id2;
                main_bucket_id2 = temp;
            }

            hash_bucket *temp_hash_bucket2 = (hash_bucket*) malloc(sizeof (hash_bucket));
            temp_hash_bucket2->bucket_level = temp_hash_bucket->bucket_level * 2;
            for (i = 0; i < HASH_BUCKET_SIZE; i++) {
                temp_hash_bucket2->element[i].value = -1;
                memset(&temp_hash_bucket2->element[i].add, 0, sizeof (struct_add));
            }
            memcpy(data, temp_hash_bucket2, sizeof (hash_bucket));
            update_bucket_in_block(hash_add, data);

            main_add = get_nth_main_bucket_add(indexName, main_bucket_id2);
            temp_block = (AK_block*) AK_read_block(main_add->addBlock);
            address = temp_block->tuple_dict[main_add->indexTd].address;
            size = temp_block->tuple_dict[main_add->indexTd].size;
            memcpy(temp_main_bucket, &temp_block->data[address], size);

            hash_add = insert_bucket_to_block(indexName, data, HASH_BUCKET);
            memcpy(&temp_main_bucket->element[hash_bucket_id2 % MAIN_BUCKET_SIZE].add, hash_add, sizeof (struct_add));
            memcpy(data, temp_main_bucket, sizeof (main_bucket));
            update_bucket_in_block(main_add, data);

            AK_change_hash_info(indexName,info->modulo,info->main_bucket_num,info->hash_bucket_num+1);
            for (i = 0; i < HASH_BUCKET_SIZE; i++) {
                int value = temp_hash_bucket->element[i].value;
                memcpy(main_add, &temp_hash_bucket->element[i].add, sizeof (struct_add));
                AK_insert_in_hash_index(indexName, value, main_add);
            }
            AK_insert_in_hash_index(indexName, hashValue, add);
        }
    }
}

/**
 Function for fetching or deleting record from hash index
 @param indexName name of index
 @param values list of values (one row) to search in hash index
 @param delete if delete is 0 then record is only read otherwise it's deleted from hash index
 @return address structure with data where the record is in table
 @author Mislav Čakarić
 */
struct_add *AK_find_delete_in_hash_index(char *indexName, AK_list *values, int delete) {
    int hashValue = 0, address, size, i, j, k, found, match;
    struct_add *add=(struct_add*) malloc(sizeof (struct_add));
    AK_list_elem temp_elem;
    temp_elem = FirstL(values);
    while (temp_elem) {
        hashValue += AK_elem_hash_value(temp_elem);
        temp_elem = NextL(temp_elem);
    }
    struct_add *main_add = (struct_add*) malloc(sizeof (struct_add));
    struct_add *hash_add = (struct_add*) malloc(sizeof (struct_add));
    main_bucket *temp_main_bucket = (main_bucket*) malloc(sizeof (main_bucket));
    hash_bucket *temp_hash_bucket = (hash_bucket*) malloc(sizeof (hash_bucket));
    char data[255];
    memset(data, 0, 255);
    hash_info *info = (hash_info*) malloc(sizeof (hash_info));
    info = AK_get_hash_info(indexName);
    int hash_bucket_id = hashValue % info->modulo;
    int main_bucket_id = (int) (hash_bucket_id / MAIN_BUCKET_SIZE);

    main_add = get_nth_main_bucket_add(indexName, main_bucket_id);
    AK_block *temp_block = (AK_block*) AK_read_block(main_add->addBlock);
    address = temp_block->tuple_dict[main_add->indexTd].address;
    size = temp_block->tuple_dict[main_add->indexTd].size;
    memcpy(temp_main_bucket, &temp_block->data[address], size);

    memcpy(hash_add, &temp_main_bucket->element[hash_bucket_id % MAIN_BUCKET_SIZE].add, sizeof (struct_add));

    temp_block = (AK_block*) AK_read_block(hash_add->addBlock);
    address = temp_block->tuple_dict[hash_add->indexTd].address;
    size = temp_block->tuple_dict[hash_add->indexTd].size;
    memcpy(temp_hash_bucket, &temp_block->data[address], size);
    for (i = 0; i < HASH_BUCKET_SIZE; i++) {
        if (temp_hash_bucket->element[i].value == hashValue) {
            AK_block *temp_table_block = (AK_block*) AK_read_block(temp_hash_bucket->element[i].add.addBlock);
            j = 0;
            while (strcmp(temp_block->header[j].att_name, "\0")) {
                k = 0;
                found = 0;
                while (strcmp(temp_table_block->header[k].att_name, "\0")) {
                    if (strcmp(temp_block->header[j].att_name, temp_table_block->header[k].att_name) == 0) {
                        found = 1;
                        match = 0;
                        int indexTd = temp_hash_bucket->element[i].add.indexTd + k;
                        int record_address = temp_table_block->tuple_dict[indexTd].address;
                        int record_size = temp_table_block->tuple_dict[indexTd].size;
                        int record_type = temp_table_block->tuple_dict[indexTd].type;
                        memcpy(data, &temp_table_block->data[record_address], record_size);
                        temp_elem = FirstL(values);
                        while (temp_elem) {
                            if (temp_elem->type == record_type && memcmp(data, &temp_elem->data, record_size) == 0)
                                match = 1;
                            temp_elem = NextL(temp_elem);
                        }
                        break;
                    }
                    k++;
                }
                if (found == 0 || match == 0) break;
                j++;
            }
            if (match) {
                int addBlock = temp_hash_bucket->element[i].add.addBlock;
                int indexTd = temp_hash_bucket->element[i].add.indexTd;
                if (delete) {
                    temp_hash_bucket->element[i].value = -1;
                    memcpy(data, temp_hash_bucket, sizeof (hash_bucket));
                    update_bucket_in_block(hash_add, data);
                } else
                    printf("Record found in table block %d and TupleDict ID %d\n", addBlock, indexTd);
                add->addBlock = addBlock;
                add->indexTd = indexTd;
                break;
            }
        }
    }
    return add;
}

/**
 Function for fetching record from hash index
 @param indexName name of index
 @param values list of values (one row) to search in hash index
 @return address structure with data where the record is in table
 @author Mislav Čakarić
 */
struct_add * AK_find_in_hash_index(char *indexName, AK_list *values) {
    return AK_find_delete_in_hash_index(indexName, values, 0);
}

/**
 Function for deleting record from hash index
 @param indexName name of index
 @param values list of values (one row) to search in hash index
 @author Mislav Čakarić
 */
void AK_delete_in_hash_index(char *indexName, AK_list *values) {
    AK_find_delete_in_hash_index(indexName, values, 1);
}

/**
 Function for creating hash index
 @param tblName name of table for which the index is being created
 @param indexName name of index
 @param attributes list of attributes over which the index is being created
 @return success or error
 @author Mislav Čakarić
 */
int AK_create_hash_index(char *tblName, list_op *attributes, char *indexName) {
    int i, j, k, l, n, exist, hashValue;
    element_op attribute;

    table_addresses *addresses = (table_addresses*) get_table_addresses(tblName);
    int num_attr = AK_num_attr(tblName);
    AK_header *table_header = AK_get_header(tblName);

    AK_header i_header[ MAX_ATTRIBUTES ];
    AK_header* temp;

    attribute = GetFirstelementOp(attributes);
    n = 0;
    while (attribute != 0) {
        exist = 0;
        for (i = 0; i < num_attr; i++) {
            if (strcmp((table_header + i)->att_name, attribute->attribute_name) == 0) {
                if(DEBUG)
                    printf("Attribute %s exist in table, found on position: %d\n", (table_header + i)->att_name, i);
                exist = 1;
                temp = (AK_header*) AK_create_header((table_header + i)->att_name, (table_header + i)->type, FREE_INT, FREE_CHAR, FREE_CHAR);
                memcpy(i_header + n, temp, sizeof ( AK_header));
                n++;
                if ((table_header + 1)->type != TYPE_VARCHAR && (table_header + 1)->type != TYPE_INT) {
                    printf("Unsupported data type for hash index! Only int and varchar!");
                    return EXIT_ERROR;
                }
            }
        }
        if (!exist) {
            printf("Atribut %s ne postoji u tablici", attribute->attribute_name);
            return EXIT_ERROR;
        }
        attribute = GetNextelementOp(attribute);
    }
    memset(i_header + n, 0, MAX_ATTRIBUTES - n);

    int startAddress = AK_initialize_new_segment(indexName, SEGMENT_TYPE_TABLE, i_header);
    if (startAddress != EXIT_ERROR)
        printf("\nINDEX %s CREATED!\n", indexName);

    AK_block *block = (AK_block*) AK_read_block(startAddress);
    hash_info *info = (hash_info*) malloc(sizeof (hash_info));
    info->modulo = 4;
    info->main_bucket_num = 0;
    info->hash_bucket_num = 0;
    memcpy(block->data, info, sizeof (hash_info));
    block->tuple_dict[0].address = 0;
    block->tuple_dict[0].type = INFO_BUCKET;
    block->tuple_dict[0].size = sizeof (hash_info);
    block->free_space += sizeof (hash_info);
    block->last_tuple_dict_id = 0;
    AK_write_block(block);

    AK_list_elem temp_elem;

    char data[ MAX_VARCHAR_LENGHT ];
    AK_list *row = (AK_list*) malloc(sizeof (AK_list));
    InitL(row);
    i = 0;
    n = 0;
    while (addresses->address_from[ i ]) {
        for (j = addresses->address_from[ i ]; j < addresses->address_to[ i ]; j++) {
            AK_block *temp = (AK_block*) AK_read_block(j);
            for (k = 0; k < DATA_BLOCK_SIZE; k += num_attr) {
                n++;
                if (temp->tuple_dict[k].type == FREE_INT)
                    break;
                for (l = 0; l < num_attr; l++) {
                    int type = temp->tuple_dict[ k + l ].type;
                    int size = temp->tuple_dict[ k + l ].size;
                    int address = temp->tuple_dict[ k + l ].address;
                    memcpy(data, &(temp->data[address]), size);
                    data[ size ] = '\0';
                    InsertAtEndL(type, &data, size, row);
                }
                /* *************** */
                hashValue = 0;
                attribute = GetFirstelementOp(attributes);
                while (attribute) {

                    for (l = 0; l < num_attr; l++) {
                        if (strcmp((table_header + l)->att_name, attribute->attribute_name) == 0)
                            break;
                    }
                    temp_elem = AK_get_nth_in_row(l, row);
                    hashValue += AK_elem_hash_value(temp_elem);

                    attribute = GetNextelementOp(attribute);
                }
                if (DEBUG)
                    printf("Insert in hash index %d. record\n", n);
                struct_add *add = (struct_add*) malloc(sizeof (struct_add));
                add->addBlock = j;
                add->indexTd = k;
                AK_insert_in_hash_index(indexName, hashValue, add);
                DeleteAllL(row);
                /* *************** */
            }
        }
        i++;
    }
    return EXIT_SUCCESS;
}

/*
int AK_delete_hash_index(char *indexName) {
    int i = 0;
    table_addresses *addresses = (table_addresses*) get_table_addresses(indexName);
    while (addresses->address_from[ i ] != 0) {
        AK_delete_extent(addresses->address_from[i], addresses->address_to[i]);
        i++;
    }
}
 */

/**
 Function for testing hash index
 @author Mislav Čakarić
 */
void hash_test() {
    char *tblName = "Student";
    char *indexName = "student_hash_index";
    create_test_table_for_hash(tblName);
    list_op *att_list = (list_op *) malloc(sizeof (list_op));
    InitializelistOp(att_list);
    InsertNewelementOp(tblName, "mbr", att_list);
    InsertNewelementOp(tblName, "firstname", att_list);

    AK_create_hash_index(tblName, att_list, indexName);

    AK_list *values = (AK_list*) malloc(sizeof (AK_list));
    AK_list *row = (AK_list*) malloc(sizeof (AK_list));
    InitL(values);
    
    hash_info *info = (hash_info*) malloc(sizeof (hash_info));
    info = AK_get_hash_info(indexName);
    printf("Main buckets:%d, Hash buckets:%d, Modulo:%d\n",info->main_bucket_num,info->hash_bucket_num,info->modulo);
    
    int i, num_rec = AK_get_num_records(tblName);
    for (i = 0; i < num_rec; i++) {
        row = AK_get_row( i, tblName );
        AK_list_elem value=AK_get_nth_in_row(0, row);
        InsertAtEndL(value->type, value->data, value->size, values);
        value=AK_get_nth_in_row(1, row);
        InsertAtEndL(value->type, value->data, value->size, values);
        AK_find_in_hash_index(indexName, values);
        DeleteAllL(values);
    }
    printf("hash_test: Present!\n");
}

