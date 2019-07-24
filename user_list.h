#ifndef _USER_LIST_H
#define _USER_LIST_H
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif
/*element member can individuate */
struct element
{  
  char  unicast[2];
  char  thingname[40];
  char  version[3];
  char  online;
  char  thing_type[20];
  char  status[30];
  char  real_status[30];
  char  delta_topic[80];
  char  update_topic[80];
  char  heartbeat_count;
  int   shadow_version;
  char  off_line_pubed;
  
};
typedef struct element ElementType;                                       
typedef struct ListNode {
    ElementType  Element;        
    struct ListNode* Next;       
}Node, *PNode;

struct user_list_fun
{
  PNode (*create_list)(void) ;
  int (*traverse_list)(PNode ) ;
  PNode (*find_list)(PNode ,ElementType ) ;
  PNode (*find_list_by_unicast)(PNode ,ElementType ) ;
  void (*insert_to_list_tail)(PNode  ,ElementType  ) ;
  void (*list_node_modify)(PNode  , ElementType  ) ;
  void (*delete_list)(PNode  , PNode  ) ;
  void (*delete_the_list)(PNode ;) ;
};
extern PNode list;
extern struct user_list_fun list_fun;
void user_list_init(void);
#endif
