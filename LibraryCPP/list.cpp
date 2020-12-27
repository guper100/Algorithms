#include <stdlib.h>
#include "list.h"

struct ListItem
{
    ListItem* next;
    Data value;
};

struct List
{
    ListItem* head;
};

List *list_create()
{
    List* list = new List;
    list->head = nullptr;
    return list;
}

void list_delete(List *list)
{
    delete list->head;
    delete list;
}

ListItem *list_first(List *list)
{
    return list->head;
}

Data list_item_data(const ListItem *item)
{
    return item->value;
}

ListItem *list_item_next(ListItem *item)
{
    return item->next;
}

//ListItem *list_item_prev(ListItem *item)
//{
//    return NULL;
//}

ListItem *list_insert(List *list, Data data)
{
    ListItem* item = new ListItem;
    item->value = data;

    item->next = list->head;
    list->head = item;

    return item;
}

ListItem *list_insert_after(List *list, ListItem *item, Data data)
{
    ListItem* new_item = new ListItem;
	new_item->value = data;

	new_item->next = item->next;
    item->next = new_item;

    return new_item;
}

//ListItem *list_erase(List *list, ListItem *item)
//{
//    return NULL;
//}

ListItem *list_erase_next(List *list, ListItem *item)
{
    ListItem* delete_item = item->next;
    item->next = delete_item->next;

	delete delete_item;
    return item;
}

ListItem *list_erase_first(List *list)
{
    ListItem* delete_item = list->head;
    list->head = list->head->next;

	delete delete_item;
	return list->head;
}
