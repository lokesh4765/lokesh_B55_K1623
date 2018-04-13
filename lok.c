 #include<stdio.h>
 int n;
 struct process
 { 
 int p_no;
 int a_t,b_t,ct,w_t,taround_time,p;
 int flag;
 int i;
 }p_list[100];
 void Sorting()
 {
 struct process p;
  int i, j;
   for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(p_list[i].a_t > p_list[j].a_t)
 {
 p = p_list[i];
 p_list[i] = p_list[j];
 p_list[j] = p;
 }
  }
 }
 }
 int main()
 {
 int i,t=0,b_t=0,peak;
 int a[10];
 float wait_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;
 printf("enter the no. of processes: ");
 scanf("%d",&n);
 for(i = 0; i < n; i++)
 {
 p_list[i].p_no = i+1;
 printf("\nEnter Details For P%d process:-\n", p_list[i].p_no);
 printf("Enter Arrival Time: ");
 scanf("%d", &p_list[i].a_t );
 printf("Enter Burst Time: ");
 scanf("%d", &p_list[i].b_t);
 p_list[i].flag = 0;
 b_t = b_t + p_list[i].b_t;
 }
 Sorting();
 for(i=0;i<n;i++)
  {
 a[i]=p_list[i].b_t;
 }
 p_list[9].b_t = 9999;
 for(t = p_list[0].a_t; t <= b_t+1;)
 {
 peak = 9;
 for(i=0;i<n;i++)
 {
 if(p_list[i].a_t <= t && p_list[i].b_t < p_list[peak].b_t && p_list[i].flag != 1)
 {
 peak = i;
 }
 if(p_list[peak].b_t==0 && p_list[i].flag != 1)
 {
p_list[i].flag = 1;
 p_list[peak].ct=t;p_list[peak].b_t=9999;
 printf("\nthe process P%d completes in %d\n",p_list[i].p_no,p_list[peak].ct);}
 }
 t++;
 (p_list[peak].b_t)--;
 }
 printf("\n-----------------------------------\n");
  for(i=0;i<n;i++)
 {
 p_list[i].taround_time=(p_list[i].ct)-(p_list[i].a_t);
 avg_taround_time=avg_taround_time+p_list[i].taround_time;
 p_list[i].w_t=((p_list[i].taround_time)-a[i]);
 avg_w_t=avg_w_t+p_list[i].w_t;
 }
 printf("PNO\tAT\tCT\tTA\tWTt\n");
 printf("-----------------------------------\n");
 for(i=0;i<n;i++)
 {
printf("P%d\t%d\t%d\t%d\t%d\n",p_list[i].p_no,p_list[i].a_t,p_list[i].ct,p_list[i].taround_time
,p_list[i].w_t); 
 }
  printf("\n-----------------------------------\n");
 printf("Average Turn around Time: %.2f\t\n\n",avg_taround_time/n);
 printf("Average Waiting Time :\t %.2f\t\n",avg_w_t/n);
 }

