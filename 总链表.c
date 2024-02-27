//链表的结点结构
struct STU
{
	//数据域
	int num;
	char name[10];
	//指针域
	struct STU *pnext; //指向下一个结点的指针
};
/*
==========================
功能：创建n个节点的链表
返回：指向链表表头的指针
==========================
*/
//搭链子+创造节点
struct STU * Create_link(int n)
{
	struct STU *phead = NULL,*p = NULL,*pf = NULL;       
// phead为头指针（保存表头结点的指针），
// p为后一结点的指针变量(指向当前节点)，
// pf为指向两相邻结点的前一结点的指针变量(指向当前节点的前一个节点)。
	int i;//计数器
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个人的数据：",i);
		p=(struct STU*)malloc(sizeof(struct STU));//分配结点空间
        if(p==NULL)//分配空间失败
         {
           printf(“分配空间失败\n”);
        // exit(0);
          break;
        }
		scanf("%d %s",&p->num,p->name); //在当前结点p的数据域中存储姓名、学号
       if(phead == NULL)    //只有一个结点
		{       
			phead=p;  //节点总数是1，phead指向刚创建的节点p
			pf=p;   //phead=pf=p
		}
		else
		{
			pf->pnext =p;   //pf指向下一个节点的首地址（新节点）
//把p的地址赋给pf所指向的节点的指针域（把p所指向的节点连接到下一个结点）, 这样就把pf和p所指向的节点连接起来了
			pf=p;   //把p的地址留给pf,然后p产生新节点
    }
	}
	p->pnext = NULL;  //单向链表的最后一个节点要指向NULL
	return phead;    //返回创建链表的头指针
}
 
 
main()
{ 
	int n,num;
	struct STU *phead; //phead用来存放链表头结点的地址
	printf("输入节点个数：");
	scanf("%d",&n);
	phead=Create_link(n);  //创建链表，把链表的头结点地址给phead
}
