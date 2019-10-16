#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long int ll;

ll evaluate(ll a, char c, ll b)
{
    ll ans;
                if(c =='+')
                    ans = a+b;
                else if(c=='-')
                    ans = b-a;
                else if (c=='*')
                    ans = b*a;
                else if (c=='/')
                    ans = b/a;
                else if (c == '|')
                    ans = b|a;
                else if(c=='&')
                    ans = b&a;
                else if (c=='^')
                    ans = b^a;
                else if (c=='(')
                    ans = b<<a;
                else if(c==')')
                    ans = b>>a;
                else if(c=='[')
                    ans = (b<=a);
                else if(c==']')
                    ans = (b>=a);
                else if(c=='=')
                    ans = (b==a);
                else if(c=='!')
                    ans = (b!=a);
                else if(c=='%')
                    ans = (b%a);
                else if (c=='<')
                    ans = (b<a);
                else if (c == '>')
                    ans = (b>a);
                else if(c=='$')
                    return 0;

        return ans;
}


int precedence(char a)
{
    if( (a=='*') || (a=='/') || (a=='%'))
        return 8;
    else if( (a=='+')  || (a=='-'))
        return 7;
    else if( (a=='(')||(a==')') )
        return 6;
    else if( (a=='[') || (a==']') || (a=='<') || (a=='>') )
        return 5;
    else if((a=='!')||(a=='='))
        return 4;
    else if(a=='&')
        return 3;
    else if(a=='^')
        return 2;
    else if(a=='|')
        return 1;
    else if(a=='$')
        return 0;
}

int isInteger(char a)
{
    if((a-'0'>=0)&&(a-'0'<=9))
        return  1;
    return 0;
}

int main()
{
    ll t;
    scanf("%lld",&t);

    while(t--)
    {
        char str[100];
        ll i = -1;
        char x;
        scanf("%c",&x);
        if(x!='\n'&&x!=' ')
            {
                i++;
                str[i] = x;
            }
        while(str[i]!='#')
        {
            scanf("%c",&x);
            if(x!='\n'&&x!=' ')
                {


                    i++;
                    if(str[i-1]=='<'&&x=='<')
                       {
                           str[i-1] = '(';
                           i--;
                       }
                    else if (str[i-1]=='>'&&x=='>')
                        {
                            str[i-1] = ')';
                            i--;
                        }
                    else if(str[i-1]=='<'&&x=='=')
                        {
                            str[i-1] = '[';
                            i--;
                        }
                    else if (str[i-1]=='>'&&x=='=')
                        {
                            str[i-1] = ']';
                            i--;
                        }
                    else if (str[i-1]=='='&&x=='=')
                        {
                            str[i-1]='=';
                            i--;
                        }
                    else if(str[i-1]=='!'&&x=='=')
                        {
                            str[i-1]='!';
                            i--;
                        }
                    else
                        str[i] = x;

                }
        }



        ll length = i;
        i=0;
     
        ll oper[100];
        oper[0] = '$';
        ll num[100];
        ll optop = 0,ans;
        ll numtop = -1;
        i = 0;
        int flag = 0,flag1= 0;
        int newnum = 0;
        int signedNum = 1;
        char pseudo;
        int pre_preced=0,preced=0;
        flag=0;
        for(i=0;i<length;i++)
        {

        if(flag == 0){
            int val = 0;
            if(flag==0&&str[i]=='-')
                {
                    signedNum = -1;
                    flag1 = 1;
                    i++;
                }
            while(isInteger(str[i]))
            {
                val = (val*10) + (str[i]-'0');
         
                i++;
            }
      
            i--;
            numtop++;
            if(flag1==1)
            val = val * signedNum;
            flag1  = 0;
            num[numtop] = val;
       
            signedNum = 1;
            val =0;


        flag=1;
        }



            else if(flag==1)
            {
               if(flag == 1){
                 char c = oper[optop];
                 optop--;
                 if(precedence(c)<precedence(str[i]))
                 {
                     optop++;
                     oper[optop] = c;
                     optop++;
                     oper[optop] = str[i];

                     flag = 0;
                 }

                 else
                 {

                     ll a = num[numtop];
                     numtop--;
                     ll b = num[numtop];
                     numtop--;
                     ll ans = evaluate(a,c,b);
                     
                     numtop++;
                     num[numtop] = ans;
                  
                     i--;
                     flag=1;
                 }
                }

            }

          

            }


            while(optop!=0)
            {
                    ll a = num[numtop];
                    numtop--;
                    ll b = num[numtop];
        
                    numtop--;
                    char c = oper[optop];
                 
                    optop--;

                    ans = evaluate(a,c,b);
                    numtop++;
                    num[numtop] = ans;
       
            }

                 printf("%lld\n",num[numtop]);
        }



}





