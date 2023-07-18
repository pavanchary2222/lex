#include<stdio.h>
#include<ctype.h>
void FIRST(char[],char);
void addToResultset(char[],char);
int numofproductions;
char productionSet[10][10];
int main()
{
    int i;
    char choice;
    char c;
    char Result[20];
    printf("How many number of productions ? :");
    scanf("%d",&numofproductions);
    for(i=0;i<numofproductions;i++)
    {
        printf("Enter productions Number %d : ",i+1);
        scanf("%s",productionSet[i]);
    }
    do
    {
        printf("\n Find the FIRST of :");
        scanf("%c",&c);
        FIRST(Result,c);
        printf("\n First(%c)={ ",c);
        for(i=0;Result[i]!='\0';i++)
            printf(" %c",Result[i]);
            printf("}\n");
            printf("press 'y' to continue : ");
            scanf("%c",&choice);
    } while (choice=='y'|| choice=='Y');

    void FIRST(char* Result,char c)
    {
        int i,j,k;
        char subResult[20];
        int foundEpsilon;
        subResult[0]='\0';
        Result[0]='\0';
        if(!(issuper(c)))
        {
            addToResultset(Result,c);
            return;
        }
        for(i=0;i<numofproductions;i++)
        {
            if(productionSet[i][0]==c)
            {
                if(productionSet[i][2]=='$')
                    addToResultset(Result,'$');
                else{
                    j=2;
                    while (productionSet[i][j]!='\0')
                    {
                        foundEpsilon=0;
                        FIRST(subResult,productionSet[i][j]);
                        for(k=0;subResult[k]!='\0';k++)
                            addToResultset(Result,subResult[k]);
                        for(k=0;subResult[k]!='\0';k++)
                            if(subResult[k]=='$')
                            {
                                foundEpsilon=1;
                            }
                            break;
                    }
                    if(!foundEpsilon)
                        break;
                    j++;
                }
            }
        }
    }
    return 0;
}
void addToResultSet(char Result[],char val)
{
    int k;
    for(k=0;Result[k]!='\0';k++)
    {
        if(Result[k]==val)
            return;
        Result[k]=val;
        Result[k+1]='\0'; 
    }
}15201803211828333191