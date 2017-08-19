    int registration()
    {
    	char uname[18];
    	char pass[18];

    	printf("Enter Username(one word) and password to register.\n");

    	scanf("%s %s",&uname,&pass);

    	int total_user=line_count("users.txt");

    	FILE *users=fopen("users.txt","a+");

    	fprintf(users,"%d\t%s\t%s\n",total_user+1,uname,pass);

    	fclose(users);
    	system("cls");

    	printf("You are successfully registered!\n");

    	first_menu();
    }
    int login()
    {
    	int number_of_users= line_count("users.txt"),id;

    	char t_user[18],t_pass[18],c_user[18],c_pass[18];

    	printf("Enter username and password to log in:\t");

    	scanf("%s %s",&t_user,&t_pass);

    	FILE *users=fopen("users.txt","r");

    	int i,sign=0;

    	for(i=0;i<number_of_users;i++)
        {
    		fscanf(users,"%d%s%s",&id,&c_user,&c_pass);

        	if(strcmp(t_user,c_user)==0&&strcmp(t_pass,c_pass)==0)
            {
                sign=1;
                system("cls");

            	printf("you are now logged in\n");

            	start_session(id,c_user,c_pass);
    			break;
    		}
    	}
    	if(sign==0)
        {
            system("cls");

            printf("password did not match!\n");

            first_menu();
    	}
        else
        {
            main_menu();
    	}

    }
    int start_session(int id,const char *uname,const char *pass)
    {
    	FILE *file=fopen("session.txt","w+");

    	fprintf(file,"%d\t%s\t%s",id,uname,pass);

    	fclose(file);
    	return 0;
    }
    int logged_in(int  cc)
    {
    	char user[18],pass[18];

    	int id;

    	FILE *users=fopen("session.txt","r");

    	fscanf(users,"%d%s%s",&id,&user,&pass);

    	fclose(users);

        if(cc==1)
        {
            puts(user);
            return -1;

        }
        else
        {
            return id;
        }
    }
    int log_out()
    {
    	FILE *file=fopen("session.txt","w+");

    	fprintf(file,"%d\t%s\t%s",0,0,0);

    	fclose(file);

        first_menu();
    	return 0;
    }
    int main_menu(){
        int cc;

        int uid=logged_in(0);

        printf("logged in as: ");

        logged_in(1);

        printf("\n");

        printf("+---------------MENU-----------------+\n");
        printf("+------------------------------------+\n");
        printf("|      A: Create Task.               |\n");
        printf("+------------------------------------+\n");
        printf("|      B: Show All tasks.            |\n");
        printf("+------------------------------------+\n");
        printf("|      C: Show today's tasks.        |\n");
        printf("+------------------------------------+\n");
        printf("|      D: Show tomorrow's tasks.     |\n");
        printf("+------------------------------------+\n");
        printf("|      E: Delete task.               |\n");
        printf("+------------------------------------+\n");
        printf("|      F: About.                     |\n");
        printf("+------------------------------------+\n");
        printf("|      G: Log out.                   |\n");
        printf("+------------------------------------+\n");
        printf("|      H: Exit.                      |\n");
        printf("+------------------------------------+\n");
        char n;
        n=getch();
        switch(n){
        case 'a':
            system("cls");
            add_tasks(uid);
            break;
        case 'b':
            system("cls");
            show_task(uid);
            break;
        case 'c':
            system("cls");
            show_today(uid);
            break;
            case 'd':
            system("cls");
            show_tomorrow(uid);
            break;
        case 'e':
            system("cls");

            printf("Enter task ID to delete:");

            scanf("%d",&cc);

            if(line_count("tasks.txt")>=cc)
            {
                        delete_task(cc,uid);
            }
            else
            {
                    printf("No id found!\n");
            }

            break;
            case 'f':
            system("cls");
            about();
            break;
        case 'g':
            system("cls");
            log_out();
            break;
        case 'h':
            logo();
            exit(0);
            break;
        default:
            printf("invalid input given. please try again");
        }
    }
    int check(int uid)
    {
      if(uid==0){
            system("cls");
        first_menu();
    }else{
    main_menu();
    }
    }

    int first_menu()
    {
        char n;
        printf("+-------------------------------+\n");
        printf("|       A: Login                |\n");
            printf("+-------------------------------+\n");
        printf("|       B: Register             |\n");
            printf("+-------------------------------+\n");
        n=getch();
        switch(n){
        case 'a':
            login();
            break;
        case 'b':
            registration();
            break;
        default:
            printf("invalid input. try again\n");
        }
    }
    int line_count(const char *filename)
    {
    	int ch = 0;
    	int count = 0;
    	FILE *file= fopen(filename, "r");

    	if(file==NULL){

    		printf("File not found\n");
    		return 0;
    	}

    	do {
    		ch = fgetc(file);
    		if ( ch == '\n')
    			count++;
    	} while (ch != EOF);

    	fclose(file);

    	return count;
    }
    about(){
    printf("+----------------------------------------+\n");
    printf("|                                        |\n");
    printf("|               TO-DO-LIST               |\n");
    printf("|                                        |\n");
    printf("|             Version 1.1.0              |\n");
    printf("|                                        |\n");
    printf("|                  ***                   |\n");
    printf("|                                        |\n");
    printf("|     Supervisor: DR. MD. ASRAF ALI      |\n");
    printf("|                                        |\n");
    printf("|         Associate Professor            |\n");
    printf("|                                        |\n");
    printf("|   Daffodil International University    |\n");
    printf("|                                        |\n");
    printf("|                  ***                   |\n");
    printf("|                                        |\n");
    printf("|   Developer: Hafijur Rahman Bokhtier   |\n");
    printf("|                                        |\n");
    printf("|       Student ID: 163-35-1739          |\n");
    printf("|                                        |\n");
    printf("|   Department of Software Engineering   |\n");
    printf("|                                        |\n");
    printf("|   Daffodil International University    |\n");
    printf("|                                        |\n");
    printf("|      MAIL: rhafijur70@yahoo.com        |\n");
    printf("+----------------------------------------+\n");
    }
