#ifndef _WATCHPRJ_H_
#define _WATCHPRJ_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define MAX 6  //定义系统用户列表最长为6

static int user_current_num = 0;//定义系统当前使用人数起始�?1

static int user_count = 1;//定义已在系统中注册的人数
static int user_current_id = -1;//当前使用的系统的用户id

char *parentName = "parent";
char *parentKeys = "123456";


struct user
{
    int id;//用户ID
    int userKind;//用户类型,普通用户为0，超级用户为1
    char name[50];//用户姓名
    char keys[50];//用户密码
    int age;//用户年龄
    char tel[50];//用户电话
    int user_in;//用户登录状�?

    int statu_study_or_play;//用户使用状�?

    time_t study_begin;
    time_t study_end;
    float study_time;
    time_t play_begin;
    time_t play_end;
    float play_time;

};
static struct user uArray[MAX] = {'0'};//用户列表
static char note[MAX][100] = { {"\0"}};

/**************************************
 * 函数定义
 * **********************************/

void init_watch();//初始�?
void menu();//功能菜单页面
void actionMenu();//登录后的主菜单页�?
void regist();//注册
void login();//登录
void change();//修改用户信息
void showMeassage();//显示kids的信�?
void noteMessage();//给孩子留言
void monitor();//监控功能
void deleteKid();//注销孩子
int exitSystem(int bk);//退出登�?
int exitChange(int bk);//切换账号

void clearScreen();//清屏

void printLogin();//显示登录界面
void printMenu();//显示主菜单界�?
void printWel();//显示欢迎界面
void printActionMenu();//显示活动菜单
void printMonitor();//显示监控页面
void printChange();//显示修改信息页面



#endif