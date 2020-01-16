#include "watchprj.h"

int main(int argc, char *argv[])
{
    init_watch();

    menu();

    return 0;
}
/*********************************************
 * 初始化程??
 * 功能：初始化,管理员固定在数组第一个位??
 * ****************************************/
void printWel()
{
    printf("================gec===================\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("||          welcome!                ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("======================================\n");
    sleep(5);
}

void init_watch()
{
    clearScreen();
    //初始化管理员，即父母
    uArray[0].id = 0;
    uArray[0].userKind = 1;
    strcpy(uArray[0].name,parentName);
    strcpy(uArray[0].keys,parentKeys);
    uArray[0].user_in = 0;//设置登录状态为未登??
    printWel();
   

}
/****************************************
 * 主菜单页??
 * 功能：显示注册、登录、退??
 * 
 * **************************************/
void printMenu()
{
    printf("================gec===================\n");
    printf("||      Please input your choise!   ||\n");
    printf("||                                  ||\n");
    printf("||            1.regist              ||\n");
    printf("||            2.login               ||\n");
    printf("||            3.exit                ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("======================================\n");
}
void menu()
{
    int mChose;
    int mbk = 0;
    while (1)
    {
        clearScreen();
        printMenu();

        scanf("%d", &mChose);
        switch (mChose)
        {
        case 1:
            regist();
            break;
        case 2:
            login();
            break;
        case 3:
            mbk = exitSystem(mbk);
        default:
            printf("input errpr,please try again!\n");
            break;
        }

        if (1 == mbk)
        {
            break;
        }
        
    }
    
    printf("thanks for use ,goodbye!\n");

}

/************************************************
 * 注册
 * 功能：为kids提供注册
 * 
 * **********************************************/
void regist()
{
    uArray[user_count].id = user_count;

    printf("pleae input your name:\n");
    scanf("%s", uArray[user_count].name);

    printf("please input your password:\n");
    scanf( "%s", uArray[user_count].keys);

    printf("please input your age:\n");
    scanf("%d", &uArray[user_count].age);

    printf("please input your tel:\n");
    scanf("%s", uArray[user_count].tel);
    user_count++;

    printf("congratulation, you regist success,system will comeback!\n");
    sleep(3);

}

/************************************************************
 * 登录
 * 功能：让普通用户和管理员登??,不同身份登录的页面不??//1
 * **********************************************************/
void printLogin()
{
    printf("================gec===================\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("||       please input login!        ||\n");
    printf("||                                  ||\n");
    printf("||       input 0 to back            ||\n");
    printf("||                                  ||\n");
    printf("======================================\n");
}
void login()
{

    char lg_name[50];
    char lg_keys[50];
    int lgbk = 0;//whlie退出条??

    while (1)
    {
        clearScreen();
        printLogin();
        printf("please input your name:\n");
        scanf("%s", lg_name);

        if (0 == strcmp("0", lg_name) )
        {
            lgbk = 1;
        }
        if (1 == lgbk )
        {
            break;
        }

        for (size_t i = 0; i < user_count; i++)
        {
            if (0 == strcmp(lg_name, uArray[i].name) )
            {
                printf("please input your password:\n");
                scanf("%s", lg_keys);
                
                if (0 == strcmp(lg_keys, uArray[i].keys) )
                {
                    printf("login success,page loading!\n");
                    uArray[i].user_in = 1;
                    user_current_id = uArray[i].id;
                    sleep(3);
                    actionMenu();
                }
                else
                {
                    printf("password error,please try again!\n");
                    sleep(3);
                    break;
                }
                
            }
             
        }

        printf("No such user,try one time!\n");
        sleep(2);
        
    }
    
}
/***************************************************
 * 活动菜单
 * 功能：系统对于用户提供的主要功能
 * ************************************************/


//子函数，监控功能

//显示监控
void printMonitor()
{
    printf("================gec===================\n");
    printf("||     0.ExitSystem                 ||\n");
    printf("||     1.PlayMonitor                ||\n");
    printf("||     2.StudyMonitor               ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("||                                  ||\n");
    printf("======================================\n");
}

void monitor()
{
    int monChoise;
    int monbk = 0;
    int start_end_choise;

    clearScreen();
    printMonitor();

    scanf("%d", &monChoise);

    switch (monChoise)
    {
    case 0:
        exitChange(monbk);
        break;
    case 1://玩耍计??
        
        printf("please make your chose,1 begin, 2 stop\n");
        scanf("%d", &start_end_choise);
        switch (start_end_choise)
        {
            case 1:
                if (uArray[user_current_id].statu_study_or_play)              //开始玩耍计??
                {
                    printf("you are already begin monitor!\n");
                }
                else
                {
                    time(&uArray[user_current_id].play_begin);
                    printf("Paly begin\n");
                    uArray[user_current_id].statu_study_or_play = 1;
                }
        
                break;
            case 2:
                if (uArray[user_current_id].statu_study_or_play == 0)    //停止计时
                {
                    printf("No monitor to stop!\n");
                }
                else if(uArray[user_current_id].statu_study_or_play == 1)
                {
                    time(&uArray[user_current_id].play_end);
                    uArray[user_current_id].play_time += difftime(uArray[user_current_id].play_end, uArray[user_current_id].play_begin);
                    printf("play stop!\n");
                    uArray[user_current_id].statu_study_or_play = 0;
                }
                else
                {
                    printf("Error,you can't end by this way !\n");
                }
                
                break;
            default:
                break;
        }
        
        break;
    case 2://学习计时
        
        printf("please make your chose,1 begin, 2 stop\n");
        scanf("%d", &start_end_choise);
        switch (start_end_choise)
        {
            case 1:
                if (uArray[user_current_id].statu_study_or_play)              //开始学习计??
                {
                    printf("you are already begin monitor!\n");
                }
                else
                {
                    time(&uArray[user_current_id].study_begin);
                    printf("Study begin\n");
                    uArray[user_current_id].statu_study_or_play = 2;
                }
        
                break;
            case 2:
                if (uArray[user_current_id].statu_study_or_play == 0)    //停止计时
                {
                    printf("No monitor to stop!\n");
                }
                else if(uArray[user_current_id].statu_study_or_play == 2)
                {
                    time(&uArray[user_current_id].study_end);
                    uArray[user_current_id].study_time += difftime(uArray[user_current_id].study_end, uArray[user_current_id].study_begin);
                    printf("Study stop!\n");
                    uArray[user_current_id].statu_study_or_play = 0;
                }
                else
                {
                    printf("Error,you can't end by this way !\n");
                }
                break;
            default:
                printf("Input error!");
                break;
        }
        break;
    
    default:
        printf("input error,please try again!\n");
        break;
    }
    printf("system coming back\n");
    sleep(3);

}


//子函数，显示用户信息

void showMeassage()
{   
    clearScreen();
    if (uArray[user_current_id].userKind == 1)
    {
        for (size_t i = 1; i < user_count; i++)
        {
            printf("id:%d\t", uArray[i].id);
            printf("name:%s\n", uArray[i].name);

            if (uArray[i].user_in)
            {
                printf("already login\t");
            }
            else
            {
                printf("not yet login\n");
            }
            switch (uArray[i].statu_study_or_play)
            {
                case 0:
                    printf("Not Ready!\n");
                    break;
                case 1:
                    printf("playing!\n");
                    break;
                case 2:
                    printf("studying!\n");
                    break;
                default:
                    printf("Unkonw error!\n");
                    break;
            }

            printf("\tstudytime:%7.2f\n", uArray[i].study_time);
            printf("\tplaytime:%7.2f\n", uArray[i].play_time);
        }
        printf("input 0 to back\n");
        
    }else
    {
        printf("name:%s\n", uArray[user_current_id].name);
        printf("\tpassword:%s\n", uArray[user_current_id].keys);

        printf("\tstudytiem:%5.2f\n", uArray[user_current_id].study_time);
        printf("\tplaytime:%5.2f\n", uArray[user_current_id].play_time);

    }
    sleep(3);
    
}

//子函数，修改用户信息
void change()
{
    int change_id;
    clearScreen();
    showMeassage();

    if (uArray[user_current_id].userKind == 1)
    {
        printf("please input the kid's id that you want to change!\n");
        scanf("%d", &change_id);

        printf("please input the name you want to change to:\n");
        scanf("%s", uArray[change_id].name);
        
        printf("please input the the age you want to change to:\n");
        scanf("%d", uArray[change_id].age);

        printf("please input the tel you want to change to :\n");
        scanf("%s", uArray[change_id].tel);

        printf("all done!\n");
        printf("System flushing!\n");
        sleep(2);
        showMeassage();
    }else
    {
        printf("please input the name you want to change to :\n");
        scanf("%s", uArray[user_current_id].name);

        printf("please input the password you want to change to :\n");
        scanf("%s", uArray[user_current_id].keys);
        
        printf("please input the password you want to change to :\n");
        scanf("%d", uArray[user_current_id].age);

        printf("please input the password you want to change to :\n");
        scanf("%s", uArray[user_current_id].tel);        
    }
        printf("all done!\n");
        printf("System flushing!\n");
        sleep(2);
        showMeassage();
        printf("system back\n");

}

//子函数，给孩子留言
void noteMessage()
{
    int noteId;
    showMeassage();

    if (0 == user_current_id)
    {
        printf("please input the id you want to note:\n");
        scanf("%d", &noteId);

        printf("please input the note message!");
        scanf("%s", note[noteId]);

        printf("note success!\n");

    }
    else
    {
        printf("No way!\n");
    }
    
    sleep(3);
}


//子函数，退出登??
int exitSystem(int bk)
{   
    bk = 1;

    uArray[user_current_id].user_in = 0;

    switch (uArray[user_current_id].statu_study_or_play)
    {
    case 1:
        time(&uArray[user_current_id].play_end);
        uArray[user_current_id].play_time += difftime(uArray[user_current_id].play_begin, uArray[user_current_id].play_end);
        break;
    case 2:
        time(&uArray[user_current_id].study_end);
        uArray[user_current_id].study_time += difftime(uArray[user_current_id].study_begin, uArray[user_current_id].study_end);
        break;
    case 0:
        break;
    default:
        printf("Out Unkonw error!\n");
        break;
    }
    uArray[user_current_id].statu_study_or_play = 0;
    printf("system coming back");
    sleep(3);
    return bk;
}
//子函数，切换账号（不退出登录，返回系统界面??
int exitChange(int bk)
{   
    bk = 1;
    return bk;
    printf("system coming back");
    sleep(3);
}

//显示函数
void printActionMenu()
{
    printf("================gec===================\n");
    printf("||     0.ExitSystem                 ||\n");
    printf("||     1.Monitor                    ||\n");
    printf("||     2.ShowMessage                ||\n");
    printf("||     3.ChangeMessage              ||\n");
    printf("||     4.NoteMessage                ||\n");
    printf("||     5.Back                       ||\n");
    printf("======================================\n");
}
//动作菜单函数
void actionMenu()
{
    int acbk = 0;
    int acChose;

    while (1)
    {
        clearScreen();
        printActionMenu();

        printf("\nplease input your choise!\n");
        scanf("%d", &acChose);
        
        switch (acChose)
        {
            case 0:
                acbk = exitSystem(acbk);
                break;
            case 1:
                monitor();
                break;
            case 2:
                showMeassage();
                break;
            case 3:
                change();
                break;
            
            case 4:
                noteMessage();
            case 5:
            acbk = exitChange(acbk);
                break;
            
            default:
                printf("input error, please try one more time!\n");
                break;
        }

        for (size_t i = 0; i < MAX; i++)
        {
            if (i == user_current_id)
            {
                printf("%s", note[i]);
            }
            
        }
        if (1 == acbk)
        {
            break;
        }
    }
    
}






void clearScreen()
{
    system("cls");
}