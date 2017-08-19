  // This header file is used to handle tasks.

// The structure that will hold task for a short time.
    struct tasks{
            char title[20];
            int id,uid,dd,mm,yy;
    }tsk;
    // function that is used to create task and insert to file.
    int add_tasks(int uid)
    {
    	printf("Enter Task title(14-20 char and use '_'  instead of space ) : \n");
    	scanf("%s",&tsk.title);

    	printf("Enter Day (EX: 5): \n");
    	scanf("%d",&tsk.dd);

    	printf("Enter  Month(EX: 9) : \n");
    	scanf("%d",&tsk.mm);

    	printf("Enter  Year(EX: 1996) : \n");
    	scanf("%d",&tsk.yy);

    	int total_task=line_count("tasks.txt");
    	FILE *tasks=fopen("tasks.txt","a+");

    	fprintf(tasks,"%d\t%d\t%d %d %d \t%s\n",total_task+1,uid,tsk.dd,tsk.mm,tsk.yy,tsk.title);

    	fclose(tasks);
    }
    // reads all tasks and show them.
    int show_task(int aid)
    {
    int c;
    char title[50];
    int mark=0;
    int i=line_count("tasks.txt");

    FILE *tasks=fopen("tasks.txt","r");

    printf("+--------+-------------------------------+---------------+\n");
    printf("| ID \t | Task Name \t\t\t | Date          |\n");
    printf("+--------+-------------------------------+---------------+\n");

    for (c=0;c<i;c++)
    {
        fscanf(tasks,"%d %d %d %d %d %s",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy,&tsk.title);

        if(aid==tsk.uid){

        mark=1;

        printf("|%d \t | %s \t\t | %d/%d/%d\t |\n",tsk.id,tsk.title,tsk.dd,tsk.mm,tsk.yy);

        printf("+--------+-------------------------------+---------------+\n");
        }
    }
    if(mark==0)
    {
            printf("Task List is empty.\n");
    }

    fclose(tasks);

    }
    // reads present day's task and show them.
    int show_today(int aid)
    {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int c;
    char title[50];
    int mark=0;

    int i=line_count("tasks.txt");
    FILE *tasks=fopen("tasks.txt","r");

    printf("+--------+-------------------------------+---------------+\n");
    printf("| ID \t | Task Name \t\t\t | Date          |\n");
    printf("+--------+-------------------------------+---------------+\n");

    for (c=0;c<i;c++)
    {
        fscanf(tasks,"%d %d %d %d %d %s",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy,&tsk.title);

        if(aid==tsk.uid && tm.tm_year + 1900==tsk.yy && tm.tm_mon + 1==tsk.mm && tm.tm_mday== tsk.dd )
        {
        mark=1;
        printf("|%d \t | %s \t\t | %d/%d/%d\t |\n",tsk.id,tsk.title,tsk.dd,tsk.mm,tsk.yy);

        printf("+--------+-------------------------------+---------------+\n");
        }
    }
    if(mark==0)
    {
            printf("Task List is empty.\n");
        }
    fclose(tasks);

    }
    // reads next day's tasks and show them.
    int show_tomorrow(int aid)
    {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int c;
    char title[50];
    int mark=0;

    int i=line_count("tasks.txt");

    FILE *tasks=fopen("tasks.txt","r");

    printf("+--------+-------------------------------+---------------+\n");
    printf("| ID \t | Task Name \t\t\t | Date          |\n");
    printf("+--------+-------------------------------+---------------+\n");

    for (c=0;c<i;c++)
    {
        fscanf(tasks,"%d %d %d %d %d %s",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy,&tsk.title);

        if(aid==tsk.uid && tm.tm_year + 1900==tsk.yy && tm.tm_mon + 1==tsk.mm && tm.tm_mday+1== tsk.dd )
        {
        mark=1;
        printf("|%d \t | %s \t\t | %d/%d/%d\t |\n",tsk.id,tsk.title,tsk.dd,tsk.mm,tsk.yy);

        printf("+--------+-------------------------------+---------------+\n");
        }
    }
    if(mark==0){
            printf("Task List is empty.\n");
        }
    fclose(tasks);

    }
    // delete tasks by their id and user id.
    int delete_task(int id,int uid)
    {
         int  mark=0;
        int c;
        FILE *tmptsk=fopen("tmp_task.txt","w+");

        int i=line_count("tasks.txt");

        FILE *tasks=fopen("tasks.txt","r");

    for (c=0;c<i;c++)
    {
        fscanf(tasks,"%d %d %d %d %d",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy);

        fgets(tsk.title,30,tasks);

        if(id==tsk.id && uid==tsk.uid){
         mark=1;
        }

    }
    if(mark==1){
    for (c=0;c<i;c++)
    {
        fscanf(tasks,"%d %d %d %d %d",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy);

        fgets(tsk.title,30,tasks);

        if(id!=tsk.id)
        {
         fprintf(tmptsk,"%d \t %d \t %d %d %d \t %s",tsk.id,tsk.uid,tsk.dd,tsk.mm,tsk.yy,tsk.title);
        }

    }
    fclose(tasks);
    fclose(tmptsk);
        tmptsk=fopen("tmp_task.txt","r");

    tasks=fopen("tasks.txt","w+");

    int j=line_count("tmp_task.txt");

    for (c=0;c<j;c++)
    {
        fscanf(tmptsk,"%d %d %d %d %d %s",&tsk.id, &tsk.uid, &tsk.dd, &tsk.mm, &tsk.yy,&tsk.title);

        fprintf(tasks,"%d \t %d \t %d %d %d \t %s\n",c+1,tsk.uid,tsk.dd,tsk.mm,tsk.yy,tsk.title);
    }
    printf("SUCCESS: Successfully Deleted the task.\n");
    }else
    {
    printf("ERROR: You are not allowed to delete this task.\n");
    }
    fclose(tasks);
    fclose(tmptsk);

    }

