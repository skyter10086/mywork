// linkdemo.c -- 链表的基本用法

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 链表的data结构
struct data {
  char name[20];
  struct data *next;
};

// 为结构和指向该结构的指针定义typedef
typedef struct data PERSON;
typedef PERSON *LINK;

int main(void)
{
  // 头指针、新指针和当前元素指针
  LINK head = NULL;
  LINK new = NULL;
  LINK current = NULL;
  LINK end = NULL;

  /* 添加第一个链表元素。
   * 虽然演示程序的链表一定为空
   * 但是程序并未假设链表为空。*/

  new = (LINK)malloc(sizeof(PERSON));
  strcpy(new->name, "Abigail");
  new->next = NULL;
  head = new;
  printf("HEAD's name is %s\n", head->name);

  // 在链表末尾添加一个元素
  // 假设链表至少有一个元素

  current = head;
  while (current->next != NULL) {
    current = current->next;
  }
   new = (LINK)malloc(sizeof(PERSON));
   current->next = new;
  new->next= NULL;
  strcpy(new->name, "Carolyn");
  current = new;
  printf("CURRENT's name is %s\n", current->name);

  // 在链表第2个位置添加1个新元素
   new = (LINK)malloc(sizeof(PERSON));
   new->next = head->next;
   head->next = new;
   strcpy(new->name, "Beatrice");

  // 按顺序打印所有的数据

  current = head;
  printf("\n***Print every node's name from head of linklist!***\n");
  while (current != NULL) {
    printf("%s\n", current->name);
    current = current->next;
  }
  printf("\n*OVER*\n");

  return 0;
}
