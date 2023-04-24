                          /* C PACKAGE SOURCE CODE:*/ 

/*FINANCE MANAGEMENT SYSTEM*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void admin();
void newcust();
void signup(char us[20],char pw[20]);
void existcust();
int login(char usid[20]);
void loan_scheme(int opn4,char usid[20]);
int calender(int d,int m,int y);
float deposit_scheme(float amt_dep,int num_years);
void search();
void del();
void customer();
int main()
{
    int opn1,opn2;
    printf("\n\t\t ***FINANCE MANAGEMENT SYSTEM*** \t\t\n");
    printf("\n\t\t           PSG FINANCE       \t\n");
    v1 :
    printf("\n 1.Admin.");
    printf("\n 2.Customer.");
    printf("\n Enter your status : ");
    scanf("%d",&opn1);
    if(opn1 != 1 && opn1 != 2)
    {
        printf("\n Invalid.");
        goto v1;
    }
    switch(opn1)
    {
        case 1 :
                admin();
                do
                {
                    system("cls");
                    v3 :
                    printf("\n 1.New Customer.");
                    printf("\n 2.Existing Customer.");
                    printf("\n 3.Search Customer Record.");
                    printf("\n 4.Delete Customer Record.");
                    printf("\n 0.Exit.");
                    printf("\n What to do ? ");
                    scanf("%d",&opn2);
                    system("cls");
                    if(opn2 !=0 && opn2 != 1 && opn2 != 2 && opn2 != 3 && opn2 != 4 && opn2 != 5)
                    {
                         printf("\n Invalid.");
                         goto v3;
                    }
                    switch(opn2)
                    {
                        case 1 :
                                newcust();
                        break;
                        case 2 :
                                existcust();
                        break;
                        case 3 :
                                search();
                        break;
                        case 4 :
                                del();
                        break;
                        case 0 :
                                exit(0);
                        break;
                    }
                }while(opn2 != 0);
        break;
        case 2 :
                customer();
        break;
    }
}
void admin()
{
    system("cls");
    char usn[20],pwd[20],p;
    int i;
    v2 :
    printf("\n Enter the USERNAME : ");
    scanf("%s",usn);
    fflush(stdin);
    printf("\n Enter the PASSWORD : ");
    i=0;
    while(i>=0)
    {
        pwd[i]=getch();
        p=pwd[i];
        if(p==13)
        {
            break;
        }
        else
        {
            printf("*");
        }
        i++;
    }
    pwd[i]='\0';
    if((strcmp(usn,"admin")==0) && (strcmp(pwd,"psg3908")==0))
    {
        printf("\n Login Successful...");
    }
    else
    {
        printf("\n Invalid..Plz Retry..!");
        goto v2;
    }
    system("cls");
}
void newcust()
{
    FILE *nw1;
    int l1,l2;
    struct details
    {
        int custcode,ln_num,dep_num,door_no;
        char usid[20],pwd[20],custname[40],mob_num[15],guardian[40],city[20],aadhaar[15],mail[50],landmark[30];
    }x;
    printf("\n Customer Code : ");
    scanf("%d",&x.custcode);
    printf("\n UserID : ");
    scanf("%s",x.usid);
    printf("\n Password : ");
    scanf("%s",x.pwd);
    signup(x.usid,x.pwd);
    nw1 = fopen(x.usid,"w");
    if(nw1 == NULL)
    {
        printf("\n Can't open the file.");
    }
    system("cls");
    printf("\n Enter the following particulars : \n");
    printf("\n Customer Name : ");
    scanf(" %[^\n]s",x.custname);
    v4 :
    printf("\n Mobile Number : ");
    scanf(" %s",x.mob_num);
    l1 = strlen(x.mob_num);
    if(x.mob_num[0] < 6 || l1 != 10)
    {
        printf("\n Invalid.");
        goto v4;
    }
    printf("\n Guardian Name : ");
    scanf(" %[^\n]s",x.guardian);
    printf("\n Landmark:");
    scanf(" %s",x.landmark);
    printf("\n Door no:");
    scanf("%d",&x.door_no);
    printf("\n City : ");
    scanf(" %[^\n]s",x.city);
    v5 :
    printf("\n Aadhaar Number : ");
    scanf(" %s",x.aadhaar);
    l2 = strlen(x.aadhaar);
    if(l2 != 12)
    {
        printf("\n Invalid.");
        goto v5;
    }
    printf("\n E-Mail ID : ");
    scanf(" %s",x.mail);
    strlwr(x.mail);
    x.ln_num = 0;
    x.dep_num = 0;
    fprintf(nw1,"%d %s %s %s %s %s %d %s %s %s %s %d %d",x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,x.door_no,x.landmark,x.city,x.aadhaar,x.mail,x.ln_num,x.dep_num);
    fclose(nw1);
}
void signup(char us[20],char pw[20])
{
    FILE *signup;
    signup = fopen("signup","a");
    if(signup == NULL)
    {
        printf("\n Error Can't Open the File.");
    }
    fprintf(signup,"%s %s\n",us,pw);
    printf("\n LOGIN CREATED");
    fclose(signup);
    system("pause");
    system("cls");
}
void existcust()
{
    struct details
    {
        int custcode,ln_num,dep_num,door_no;
        char usid[20],pwd[20],custname[40],mob_num[15],guardian[40],city[20],aadhaar[15],mail[50],landmark[30];
    }x;
    struct deposit
    {
        int num_years;
        float amt_dep,dep_amt;
        struct date
        {
            int day,month,year;
        }d3,d4;
    }d;
    FILE *details, *deposit;
    int v6,opn3,opn4,num_years;
    char usid[20],snumdeposit[10],depositID[10];
    float amt_dep,dep_amt;
    printf("\n Enter the USER ID : ");
    scanf("%s",usid);
    v6 = login(usid);
    if(v6 == 1)
    {
        v7:
        system("cls");
        printf("\n 1.Loan.");
        printf("\n 2.Deposit.");
        printf("\n Do you want loan OR deposit ? ");
        scanf("%d",&opn3);
        if(opn3 != 1 && opn3 != 2)
        {
            printf("\n Invalid.");
            goto v7;
        }
        system("cls");
        switch(opn3)
        {
            case 1 :
                    v8 :
                    printf("\n 1.New Loan.");
                    printf("\n 2.Existing Loan.");
                    printf("\n Enter your choice : ");
                    scanf("%d",&opn4);
                    if(opn4 != 1 && opn4 != 2)
                    {
                        printf("\n Invalid.");
                        goto v8;
                    }
                    system("cls");
                    loan_scheme(opn4,usid);
            break;
            case 2 :
                    details = fopen(usid,"r");
                    if(details == NULL)
                    {
                        printf("\n Error Can't open the file.");
                    }
                    fscanf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",&x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,&x.door_no,x.landmark,x.city,x.aadhaar,x.mail,&x.ln_num,&x.dep_num);
                    x.dep_num = x.dep_num + 1;
                    fclose(details);
                    details = fopen(usid,"w");
                    if(details == NULL)
                    {
                        printf("\n Error Can't open the file.");
                    }
                    fprintf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,x.door_no,x.landmark,x.city,x.aadhaar,x.mail,x.ln_num,x.dep_num);
                    fclose(details);
                    sprintf(snumdeposit,"%d",x.dep_num);
                    strcat(snumdeposit,"D");
                    strcat(snumdeposit,usid);
                    strcpy(depositID,snumdeposit);
                    deposit = fopen(depositID,"w");
                    if(deposit == NULL)
                    {
                        printf("\n Error Can't open the file.");
                    }
                    printf("\n             DEPOSIT SCHEMES");
                    printf("\n       DEPOSIT             INTEREST ");
                    printf("\n (i)   Till 3 years        2 percent.");
                    printf("\n (ii)  3 to 6 years        Half the deposit amount.");
                    printf("\n (iii) Above 6 years       Equal the deposit amount.");
                    v13 :
                    printf("\n Enter the no.of years : ");
                    scanf("%d",&d.num_years);
                    num_years = d.num_years;
                    if(num_years <= 0)
                    {
                        printf("\n Invalid.");
                        goto v13 ;
                    }
                    v14 :
                    printf("\n Amount deposited : ");
                    scanf("%f",&d.amt_dep);
                    amt_dep = d.amt_dep;
                    if(amt_dep < 0)
                    {
                        printf("\n Invalid.");
                        goto v14;
                    }
                    system("cls");
                    d.dep_amt = deposit_scheme(amt_dep,num_years);
                    printf("\n Amount available after the completion of deposit scheme : %f",d.dep_amt);
                    printf("\n Starting date : ");
                    scanf("%d.%d.%d",&d.d3.day,&d.d3.month,&d.d3.year);
                    printf("\n Expiry date : ");
                    scanf("%d.%d.%d",&d.d4.day,&d.d4.month,&d.d4.year);
                    fprintf(deposit,"%s %f %d %f %d.%d.%d %d.%d.%d",depositID,d.amt_dep,d.num_years,d.dep_amt,d.d3.day,d.d3.month,d.d3.year,d.d4.day,d.d4.month,d.d4.year);
                    printf("\n Amount deposited successfully.");
                    printf("\n Deposit ID : %s",depositID);
                    printf("\n Please note this for future reference!");
                    fclose(deposit);
                    system("pause");
            break;
        }
    }
}
int login(char usid[20])
{
    int i;
    char us1[20], pw1[20],pw[20],p;
    FILE *signup;
    printf("\n Enter the PASSWORD : ");
    i=0;
    while(i>=0)
    {
        pw[i]=getch();
        p=pw[i];
        if(p==13)
        {
            break;
        }
        else
        {
            printf("*");
        }
        i++;
    }
    pw[i]='\0';
    signup=fopen("signup","r");
    if(signup == NULL)
    {
        printf("\n Error Can't open the file.");
    }
    while(1)
    {
        fscanf(signup,"%s %s",us1,pw1);
        if(feof(signup))
        {
            break;
        }
        if(strcmp(usid,us1)==0)
        {
            if(strcmp(pw,pw1)==0)
            {
                printf("\n Login Successful...");
                return 1;
                break;
            }
            else
            {
                return 0;
            }
        }
    }
    fclose(signup);
    system("cls");
}
void loan_scheme(int opn4,char usid[20])
{
    FILE *details, *loanf, *loan;
    int ln_num,date,opn5,count;
    char snumloan[10],search[10];
    struct details
    {
        int custcode,ln_num,dep_num,door_no;
        char usid[20],pwd[20],custname[40],mob_num[15],guardian[40],city[20],aadhaar[15],mail[50],landmark[30];
    }x;
    struct loan
    {
        int ln_no,paid_months;
        char usid[20];
        struct date
        {
            int day,month,year;
        }d1,d2;
        float ln_amt,amt_paid,balance_amt,int_amt,int_amt_paid;
    }l;
    details = fopen(usid,"r");
    if(details == NULL)
    {
        printf("\n Error Can't open the file.");
    }
    fscanf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",&x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,&x.door_no,x.landmark,x.city,x.aadhaar,x.mail,&x.ln_num,&x.dep_num);
    switch(opn4)
    {
        case 1 :
                ln_num = x.ln_num + 1;
                fclose(details);
                details = fopen(usid,"w");
                if(details == NULL)
                {
                    printf("\n Error Can't open the file.");
                }
                x.ln_num = ln_num;
                fprintf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,x.door_no,x.landmark,x.city,x.aadhaar,x.mail,x.ln_num,x.dep_num);
                fclose(details);
                strcpy(l.usid,x.usid);
                sprintf(snumloan,"%d",ln_num);
                strcat(snumloan,usid);
                loanf = fopen(snumloan,"w");
                if(loanf == NULL)
                {
                    printf("\n Error Can't open the file.");
                }
                l.ln_no = ln_num;
                printf("\n Loan date (dd.mm.yyyy) : ");
                scanf("%d.%d.%d",&l.d1.day,&l.d1.month,&l.d1.year);
                v9 :
                printf("\n Loan Amount : ");
                scanf("%f",&l.ln_amt);
                if(l.ln_amt < 0)
                {
                    printf("\n Invalid.");
                    goto v9;
                }
                l.amt_paid = 0;
                l.balance_amt = l.ln_amt;
                l.int_amt = 0;
                l.int_amt_paid = 0;
                l.paid_months = 0;
                date = calender(l.d1.day,l.d1.month,l.d1.year);
                l.d2.day = date / 1000000;
                date = date % 1000000;
                l.d2.month = date / 10000;
                l.d2.year = date % 10000;
                fprintf(loanf,"%d %d.%d.%d %f %f %f %f %f %d %d.%d.%d %s\n",l.ln_no,l.d1.day,l.d1.month,l.d1.year,l.ln_amt,l.amt_paid,l.balance_amt,l.int_amt,l.int_amt_paid,l.paid_months,l.d2.day,l.d2.month,l.d2.year,l.usid);
                printf("\n Your LOAN ID : %s",snumloan);
                printf("\n Please note this for future reference!");
                fclose(loanf);
                system("pause");
                system("cls");
        break;
        case 2 :
                printf("\n Enter your loan ID : ");
                scanf("%s",search);
                loan = fopen(search,"r");
                if(loan == NULL)
                {
                    printf("\n Error Can't open the file.");
                }
                fscanf(loan,"%d %d.%d.%d %f %f %f %f %f %d %d.%d.%d %s\n",&l.ln_no,&l.d1.day,&l.d1.month,&l.d1.year,&l.ln_amt,&l.amt_paid,&l.balance_amt,&l.int_amt,&l.int_amt_paid,&l.paid_months,&l.d2.day,&l.d2.month,&l.d2.year,l.usid);
                if(strcmp(l.usid,usid)==0)
                {
                    v10 :
                    printf("\n Monthly Interest 2 percent.");
                    printf("\n 1.To pay the loan amount.");
                    printf("\n 2.To pay the interest.");
                    printf("\n Enter the choice : ");
                    scanf("%d",&opn5);
                    if(opn5 != 1 && opn5 != 2)
                    {
                        printf("\n Invalid.");
                        goto v10;
                    }
                    system("cls");
                    switch(opn5)
                    {
                        case 1 :
                                v11 :
                                printf("\n Loan Amount : ");
                                scanf("%f",&l.amt_paid);
                                if(l.amt_paid > l.ln_amt)
                                {
                                    printf("\n Invalid.");
                                    goto v11;
                                }
                                l.balance_amt = l.balance_amt - l.amt_paid;
                                l.int_amt = l.balance_amt * (2.0 / 100);
                                printf("\n Details updated.");
                                system("pause");
                                system("cls");
                        break;
                        case 2 :
                                l.int_amt = l.balance_amt * (2.0 / 100);
                                printf("\n Interest amount to be paid : %f",l.int_amt);
                                v12 :
                                printf("\n Amount of interest paid : ");
                                scanf("%f",&l.int_amt_paid);
                                if(l.int_amt_paid != l.int_amt)
                                {
                                    printf("\n Invalid.");
                                    goto v12;
                                }
                                count = l.paid_months;
                                count++;
                                printf("\n No.of months interest paid : %d",count);
                                l.paid_months = count;
                                printf("\n Details updated.");
                                system("pause");
                                system("cls");
                        break;
                    }
                }
                fclose(loan);
                loan = fopen(search,"w");
                fprintf(loan,"%d %d.%d.%d %f %f %f %f %f %d %d.%d.%d %s\n",l.ln_no,l.d1.day,l.d1.month,l.d1.year,l.ln_amt,l.amt_paid,l.balance_amt,l.int_amt,l.int_amt_paid,l.paid_months,l.d2.day,l.d2.month,l.d2.year,l.usid);
                fclose(loan);
                system("pause");
                system("cls");
    }
}
int calender(int d,int m,int y)
{
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int nd,nm,ny,nd1,date;
    nd1 = month[m-1];
    if(m==2)
    {
        if(y % 100 == 0)
        {
            if(y % 400 == 0)
            {
                nd1 = 28;
            }
        }
        else
        {
            if(y % 4 == 0)
            {
                nd1 = 29;
            }
        }
    }
    nd = d + 31;
    nm = m;
    ny = y;
    if(nd > nd1)
    {
        nd = nd - nd1;
        nm++;
    }
    if(nm > 12)
    {
        nm = 1;
        ny++;
    }
    date = nd * 1000000 + nm * 10000 + ny;
    return date;
}
float deposit_scheme(float amt_dep,int num_years)
{
    float dep_amt_int,dep_amt;
    if(num_years > 0 && num_years < 3)
    {
        dep_amt_int = amt_dep * (2.0 / 100);
        dep_amt = dep_amt_int + amt_dep;
        return dep_amt;
    }
    else if(num_years >= 3 && num_years < 6)
    {
        dep_amt_int = amt_dep / 2.0;
        dep_amt = dep_amt_int + amt_dep;
        return dep_amt;
    }
    else
    {
        dep_amt_int = amt_dep;
        dep_amt = dep_amt_int + amt_dep;
        return dep_amt;
    }
}
void search()
{
   struct details
    {
        int custcode,ln_num,dep_num,door_no;
        char usid[20],pwd[20],custname[40],mob_num[15],guardian[40],city[20],aadhaar[15],mail[50],landmark[30];
    }x;
    struct loan
    {
        int ln_no,paid_months;
        char usid[20];
        struct date
        {
            int day,month,year;
        }d1,d2;
        float ln_amt,amt_paid,balance_amt,int_amt,int_amt_paid;
    }l;
    struct deposit
    {
        int num_years;
        float amt_dep,dep_amt;
        struct date d3,d4;
    }d;
    int opn6;
    char usid[30],loanid[20],depid[20],depositID[20],another='Y';
    FILE *details,*loan,*deposit;
    while(another == 'Y' || another == 'y'){
          system("cls");
          printf("\n 1.To view customer's details.");
          printf("\n 2.To view loan details.");
          printf("\n 3.To view deposit details.");
          printf("\n Enter what to search ? ");
          scanf("%d",&opn6);
          system("cls");
          switch(opn6)
          {
              case 1:
                     printf("\n Enter the USERID : ");
                     scanf("%s",usid);
                     details = fopen(usid,"r");
                     if(details == NULL)
                     {
                          printf("\n No login found in this user ID (Invalid userID).");
                          break;
                     }
                     while(fscanf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",&x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,&x.door_no,x.landmark,x.city,x.aadhaar,x.mail,&x.ln_num,&x.dep_num)!=EOF);
                     printf("\n\t\t Customer code  : %d\n\t\t User ID        : %s\n\t\t Password       : %s\n\t\t Customer name  : %s\n\t\t Phone number   : %s\n\t\t Guardian name  : %s\n\t\t Door no        : %d\n\t\t Landmark       : %s\n\t\t City           : %s\n\t\t Aadhaar No     : %s\n\t\t Mail ID        : %s\n\t\t No.of.loans    : %d\n\t\t No.of.deposits : %d\n",x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,x.door_no,x.landmark,x.city,x.aadhaar,x.mail,x.ln_num,x.dep_num);
                     fclose(details);
              break;
              case 2:
                     printf("\n Enter the LOAN ID : ");
                     scanf("%s",loanid);
                     loan = fopen(loanid,"r");
                     if(loan == NULL)
                     {
                          printf("\n There is no loan in this ID.");
                          break;
                     }
                     while(fscanf(loan,"%d %d.%d.%d %f %f %f %f %f %d %d.%d.%d %s\n",&l.ln_no,&l.d1.day,&l.d1.month,&l.d1.year,&l.ln_amt,&l.amt_paid,&l.balance_amt,&l.int_amt,&l.int_amt_paid,&l.paid_months,&l.d2.day,&l.d2.month,&l.d2.year,l.usid)!=EOF);
                     printf("\n\t\t Loan no \t\t: %d\n\t\t Loan date \t\t: %d.%d.%d\n\t\t Loan amount \t\t: %f\n\t\t Loan amount paid \t: %f\n\t\t Balance amount to pay  : %f\n\t\t Interest amount \t: %f\n\t\t Interest amount paid   : %f\n\t\t No.of.months paid \t: %d\n\t\t Due date \t\t: %d.%d.%d\n\t\t User ID \t\t: %s\n",l.ln_no,l.d1.day,l.d1.month,l.d1.year,l.ln_amt,l.amt_paid,l.balance_amt,l.int_amt,l.int_amt_paid,l.paid_months,l.d2.day,l.d2.month,l.d2.year,l.usid);
                     fclose(loan);
              break;
              case 3:
                     printf("\n Enter the DEPOSIT ID : ");
                     scanf("%s",depid);
                     deposit = fopen(depid,"r");
                     if(deposit == NULL)
                     {
                          printf("\n There is no deposit in this ID.");
                          break;
                     }
                     while(fscanf(deposit,"%s %f %d %f %d.%d.%d %d.%d.%d",depositID,&d.amt_dep,&d.num_years,&d.dep_amt,&d.d3.day,&d.d3.month,&d.d3.year,&d.d4.day,&d.d4.month,&d.d4.year) != EOF);
                     printf("\n\t\t Deposit ID        \t\t\t: %s\n\t\t Deposit amount \t\t\t: %f\n\t\t No.of years to be deposited \t\t: %d\n\t\t Amount available after deposition      : %f\n\t\t Starting date \t\t\t\t: %d.%d.%d\n\t\t Ending date \t\t\t\t: %d.%d.%d\n",depositID,d.amt_dep,d.num_years,d.dep_amt,d.d3.day,d.d3.month,d.d3.year,d.d4.day,d.d4.month,d.d4.year);
                     fclose(deposit);
              break;
          }
          printf("\n Do you want to search another record ? ");
          fflush(stdin);
          another = getche();
    }
}
void del()
{
    FILE *details,*loan,*deposit;
    char usid[20],loanid[20],depid[20],another='Y';
    int opn7;
    while(another == 'Y' || another == 'y'){
          system("cls");
          printf("\n 1.To delete Customer details.");
          printf("\n 2.To delete Loan.");
          printf("\n 3.To delete Deposit.");
          printf("\n Enter what to do delete ? ");
          scanf("%d",&opn7);
          system("cls");
          switch(opn7)
          {
              case 1:
                     printf("\n Enter the USER ID to deleted : ");
                     scanf("%s",usid);
                     if(usid == NULL)
                     {
                          printf("\n No login found in this user ID (Invalid USERID).");
                     }
                     if(remove(usid)==0)
                     {
                          printf("\n File has been deleted successfully!!!");
                     }
                     else
                     {
                          printf("\n Unable to delete the file!!!\n");
                     }
              break;
              case 2:
                     printf("\n Enter the LOAN ID to be deleted : ");
                     scanf("%s",loanid);
                     if(loanid == NULL)
                     {
                          printf("\n There is no loan in this ID.");
                     }
                     if(remove(loanid) == 0)
                     {
                          printf("\n File has been deleted successfully!!!\n");
                     }
                     else
                     {
                          printf("\n Unable to delete the file!!!");
                     }
              break;
              case 3:
                     printf("\n Enter the DEPOSIT ID to be deleted : ");
                     scanf("%s",depid);
                     if(depid==NULL)
                     {
                          printf("\n There is no deposit in this ID.");
                     }
                     if(remove(depid) == 0)
                     {
                          printf("\n File has been deleted successfully!!!");
                     }
                     else
                     {
                          printf("\n Unable to delete the file!!!");
                     }
              break;
          }
          system("pause");
          system("cls");
          printf("\n Do you want to delete another record ? ");
          fflush(stdin);
          another = getche();
    }
}
void customer()
{
    system("cls");
    FILE *details,*loan,*deposit;
    struct details
    {
        int custcode,ln_num,dep_num,door_no;
        char usid[20],pwd[20],custname[40],mob_num[15],guardian[40],city[20],aadhaar[15],mail[50],landmark[30];
    }x;
    struct loan
    {
        int ln_no,paid_months;
        char usid[20];
        struct date
        {
            int day,month,year;
        }d1,d2;
        float ln_amt,amt_paid,balance_amt,int_amt,int_amt_paid;
    }l;
    struct deposit
    {
        int num_years;
        float amt_dep,dep_amt;
        struct date d3,d4;
    }d;

    char usid[20],loanid[20],depid[20],depositID[20],another='Y';
    int opn8;
    printf("\n Enter your USER ID:");
    scanf("%s",usid);
    login(usid);
    system("cls");
    while(another == 'Y' || another == 'y'){
          system("cls");
          printf("\n 1.To view your personal details.");
          printf("\n 2.To view loan details.");
          printf("\n 3.To view deposit details.");
          printf("\n 0.Exit.");
          printf("\n Enter what to view ? ");
          scanf("%d",&opn8);
          system("cls");
          switch(opn8)
          {
              case 1:
                     printf("\n Enter the USER ID to view your details : ");
                     scanf("%s",usid);
                     details = fopen(usid,"r");
                     if(usid == NULL)
                     {
                          printf("\n No login found in this USERID (Invalid userID).");
                     }
                     while(fscanf(details,"%d %s %s %s %s %s %d %s %s %s %s %d %d",&x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,&x.door_no,x.landmark,x.city,x.aadhaar,x.mail,&x.ln_num,&x.dep_num)!=EOF);
                     printf("\n\t\t Customer code  : %d\n\t\t User ID        : %s\n\t\t Password       : %s\n\t\t Customer name  : %s\n\t\t Phone number   : %s\n\t\t Guardian name  : %s\n\t\t Door no        : %d\n\t\t Landmark       : %s\n\t\t City           : %s\n\t\t Aadhaar No     : %s\n\t\t Mail ID        : %s\n\t\t No.of.loans    : %d\n\t\t No.of.deposits : %d\n",x.custcode,x.usid,x.pwd,x.custname,x.mob_num,x.guardian,x.door_no,x.landmark,x.city,x.aadhaar,x.mail,x.ln_num,x.dep_num);
                     fclose(details);
                     system("pause");
               break;
               case 2:
                      printf("\n Enter your LOAN ID to view your loan details : ");
                      scanf("%s",loanid);
                      loan = fopen(loanid,"r");
                      if(loanid == NULL)
                      {
                          printf("\n There is no loan in this ID.");
                      }
                      while(fscanf(loan,"%d %d.%d.%d %f %f %f %f %f %d %d.%d.%d %s\n",&l.ln_no,&l.d1.day,&l.d1.month,&l.d1.year,&l.ln_amt,&l.amt_paid,&l.balance_amt,&l.int_amt,&l.int_amt_paid,&l.paid_months,&l.d2.day,&l.d2.month,&l.d2.year,l.usid)!=EOF);
                      printf("\n\t\t Loan no \t\t: %d\n\t\t Loan date \t\t: %d.%d.%d\n\t\t Loan amount \t\t: %f\n\t\t Loan amount paid \t: %f\n\t\t Balance amount to pay  : %f\n\t\t Interest amount \t: %f\n\t\t Interest amount paid   : %f\n\t\t No.of.months paid \t: %d\n\t\t Due date \t\t: %d.%d.%d\n\t\t User ID \t\t: %s\n",l.ln_no,l.d1.day,l.d1.month,l.d1.year,l.ln_amt,l.amt_paid,l.balance_amt,l.int_amt,l.int_amt_paid,l.paid_months,l.d2.day,l.d2.month,l.d2.year,l.usid);
                      fclose(loan);
                      system("pause");
                break;
                case 3:
                       printf("\n Enter the DEPOSIT ID to view your deposit details : ");
                       scanf("%s",depid);
                       deposit = fopen(depid,"r");
                       if(depid == NULL)
                       {
                           printf("\n There is no deposit in this ID.");
                       }
                       while(fscanf(deposit,"%s %f %d %f %d.%d.%d %d.%d.%d",depositID,&d.amt_dep,&d.num_years,&d.dep_amt,&d.d3.day,&d.d3.month,&d.d3.year,&d.d4.day,&d.d4.month,&d.d4.year) != EOF);
                       printf("\n\t\t Deposit ID        \t\t\t: %s\n\t\t Deposit amount \t\t\t: %f\n\t\t No.of years to be deposited \t\t: %d\n\t\t Amount available after deposition      : %f\n\t\t Starting date \t\t\t\t: %d.%d.%d\n\t\t Ending date \t\t\t\t: %d.%d.%d\n",depositID,d.amt_dep,d.num_years,d.dep_amt,d.d3.day,d.d3.month,d.d3.year,d.d4.day,d.d4.month,d.d4.year);
                       fclose(deposit);
                       system("pause");
                 break;
                default :
                         exit(0);
                 break;
          }
    }
}
