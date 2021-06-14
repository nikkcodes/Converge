#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define V 8
#define INF 9999
void solution(int dist[][V],int visited[]);
string sponser[V]={"Jaypee","Gyani_Guru","Crona_Academy","Hairport","Frequent_bakes","RedBull","IronMan","Wat_a_Burger"};
string  food[5] = {"burger","momos","pizza","maggi","rice_curd"};
void activity()
{
    int i,j,k,x=0,suure=0;
    char ch='Y';
    string str;
    vector<string> choice;
    int prior[7];
    int finish[18]={0,15,16,17,16,15,13,16,12,16,13,17,13,14,17,15,13,5};
    int start[18] ={0,13,15,16,15,12,11,14,11,15,11,14,10,11,14,12,10,15};
    int status[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int sure[18] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int u_choice[10];
    int count=0;
    string event[18]={"","group_dance","solo_dance","on_spot_dance","piksel","jus_do_it","circuit_building","robo_race","singing","antakshri","code_creed","guess_the_code","hackathon","treasure_hunt","exhibition","pubg","rangmanch","mono_dono_tino"};
    string category[22]={"","Jhankar--1","1","3","JPEG--2","4","5","CICE--3","6","7","Crescendo--4","8","9","Knuth--5","10","12","Games--6","13","15","Entertainment-7","16","17"};
    for(i=1;i<22;i=i+3)
    {
        cout<<category[i]<<endl;
        for(j=(stoi)(category[i+1]);j<=(stoi)(category[i+2]);j++)
        cout<<"....."<<event[j]<<endl;
    }
    while(ch=='Y' ||ch=='y')
    {
        cout<<"enter priority"<<endl;
        cin>>prior[x++];

        cout<<"Want to add more Priority press Y"<<endl;
        cin>>ch;
    }
    for(i=0;i<x;i++)
    {
        cout<<category[prior[i]*2+(prior[i]-2)];
        for(j=(stoi)(category[prior[i]*2+(prior[i]-2)+1]);j<=(stoi)(category[prior[i]*2+(prior[i]-2)+2]);j++)
      {
          status[j]=1;
            //u_choice[count++]=event[j];
        cout<<"....."<<event[j]<<" "<<start[j]<<"-"<<finish[j]<<endl;
    }
    }
    ch='y';// for giving choice number
    //for(i=0;i<18;i++)
   // cout<<status[i]<<" ";
    i=0;
    while(ch=='Y'||ch=='y')
    {
        cout<<"enter the event"<<endl;
        cin>>str;
        choice.push_back(str);
        for(i=0;i<18;i++)
        {
            if(str.compare(event[i])==0)
            {
                for(k=0;k<18;k++)
                {
                    if((start[k]>=start[i] && start[k]<finish[i]) || (finish[k]<=finish[i] && finish[k]>start[i]) || (start[k]<=start[i] && finish[k]>=finish[i]))
                    {
                        if(status[k]==1 && i!=k)
                        {
                        cout<<"you cant take part in "<<event[k]<<" event"<<endl;
                        sure[k]=-1;

                        }
                    }

                }
                cout<<"Do you Agree press 1"<<endl;
                    cin>>suure;
                    if(suure)
                    {
                        for(j=0;j<18;j++)
                        {
                            if(sure[j]==-1)
                            {
                                status[j]=0;
                            }
                        }

                    }
                    else{
                        memset(sure, 0, 18);
                        //i--;
                    }
            }
        }
        cout<<"do you want to enter another event press Y"<<endl;
        cin>>ch;
    }
}
void graphics()
{
        char c,d;
    FILE *fptr1;

    FILE *fptr = fopen("converse.txt", "r");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return ;
    }

    while (c != EOF)
    {
    //setColor(12);
        printf ("%c", c);
        c = fgetc(fptr);
    }

    printf("\n");

/*    while (d != EOF)
    {//setColor(5);
        printf ("%c", d);
        d = fgetc(fptr);
    }
    */

    fclose(fptr);
}

void printSolution(int dist[][V]);


void floydWarshall (int graph[][V])
{
    int visited[V];
    int dist[V][V], i, j, k;


    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];


    for (k = 0; k < V; k++)
    {

        for (i = 0; i < V; i++)
        {

            for (j = 0; j < V; j++)
            {

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    visited[0]=2;
    for(i=1;i<V;i++)
    {
        visited[i]=1;
    }

    printSolution(dist);
    solution(dist,visited);
}


void printSolution(int dist[][V])
{
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"   ";
            else
                cout<<dist[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void solution(int dist[][V],int visited[])
{
    int x=0,b=0,i,c=2,j;
    while(c<11)
    {
        x=b;
        visited[x]=visited[x]-1;
      cout<<"->"<<sponser[x];
       int  min=INT_MAX;
         //cout<<min<<endl;
    for(i=0;i<V;i++)
    {
        if(dist[x][i]<=min && dist[x][i]!=0 && visited[i]!=0)
        {
           // cout<<x<<endl;
               min=dist[x][i];
               b=i;
        }
    }
    c++;

}
cout<<endl;
}
void mapp()
{
    cout<<"**************************************************************************************************************************************************************************"<<endl;
    cout<<"*  |-------|                   |--------|------------------------------------------------------------------------------------------                                       *"<<endl;
    cout<<"*  |       |         5         |        |              |-------|<------------------------------7------------|-------------|        |                                      *"<<endl;
    cout<<"*  | Jaypee|------------------>| GYANI  |     6        | CRONA |-----------------  |-----------3----------->|    RED      |        |                                      *"<<endl;
    cout<<"*  |COLLEGE|                   |  GURU  |------------> | ACDMY |         7      |  |                        |    BULL     |<---6---|                                      *"<<endl;
    cout<<"*  |       |                   |________|              |       |               \\/  |                        |             |        |                                      *"<<endl;
    cout<<"*  |       |<--------                                  |_______|            |------------|                  |-------------|        |                                      *"<<endl;
    cout<<"*  |-------|        |                                    |                ->|WAT A BURGER|                        |                |                                      *"<<endl;
    cout<<"*      ^  |         |                                    |                | |----^-------|                        |                |                                      *"<<endl;
    cout<<"*      |  |         |                                    |                |      |_ _ _ _ _ _ _ _ _               |                |                                      *"<<endl;
    cout<<"*      |  |         | _ _ _ 7 _ _   _ _ _ _ _ _ _ _ _ _ _| _ _ _ _ _4_ _ _|_ _ _ _ _ _    _ _ _ _ _|_ _ _ _ _ _ _ |                |                                      *"<<endl;
    cout<<"*      |  |__________________________1___________________|________________|________   |  |         |              |                |                                      *"<<endl;
    cout<<"*      18                                                                 |        |  |  |1        |              8                |                                      *"<<endl;
    cout<<"*      |                                                                  |     16 |  |  |         |              |                |                                      *"<<endl;
    cout<<"*      |   |---------|                                                    |        |  |  |         3              |                |                                      *"<<endl;
    cout<<"*      |   |         |                                                    |       \\/ \\/ \\/         |             \\/                |                                      *"<<endl;
    cout<<"*      |___|   HAIR  |--------------------------------1--------------------     |--------------|   |         |------------|        |                                      *"<<endl;
    cout<<"*          |   PORT  |                                                          |              |   |_________|            |        |                                      *"<<endl;
    cout<<"*          |         |<---------------------------9-----------------------------|  FREQUENT    |             |   IRON     |<---4---|                                      *"<<endl;
    cout<<"*          |         |                                                          |    BAKES     |             |    MAN     |                                               *"<<endl;
    cout<<"*          |         |                                                          |_ _ _ _ _ _ _ |             |            |                                               * "<<endl;
    cout<<"*          |---------|<--------------------------10----------------------------------------------------------|____________|                                               *"<<endl;
    cout<<"**************************************************************************************************************************************************************************"<<endl;
    cout<<endl;

}


void rearrange(vector < int > order)
{
    make_heap(order.begin(), order.end());
    cout << "The maximum selling order is : ";
    cout << order.front() << endl;
    cout << food[order.front()]<<"\n";
    cout << "want to find next best selling press 1" <<endl;
    int chooose=0;
    cin >> chooose;
    if(chooose==1){
        pop_heap(order.begin(), order.end());
        cout << order.front() << endl;
        cout << food[order.front()]<<endl;
    }

}

void buy(int x, vector < int > &orders)
{
    orders.at(x) += 1;

    for (unsigned i=0; i<orders.size(); i++)
    std::cout << ' ' << orders.at(i);
  std::cout << '\n';

}
//myvector.at(i)


int main()
{ //   ClearConsoleToColors(0,15);
int opt=0;
int n,cho;
graphics();
    int graph[V][V] = { {0, 1, INF, INF,16,INF,INF,5},
                        {INF, 0, 6, INF,INF,6,4,INF},
                        {7, INF,0, INF,4,INF,INF,7},
                        {18,INF, INF,0,INF,INF,INF,1},
                        {INF, INF, INF, 9,0,INF,INF,INF},
                        {INF,INF, 7, INF,1,0,8,INF},
                        {INF, INF, INF, 10,INF,INF,0,3},
                        {INF,INF, INF, INF,INF,3,INF,0}
                    };
do{//ClearConsoleToColors(0,15);
   printf("\n");
   system("CLS");
   graphics();
   printf("\t\t\t\t\t1.To know the path you have to follow is \n\n");//
   printf("\t\t\t\t\t2.To participate in events please choose \n\n");//
   scanf("\t\t\t\t\t\n%d",&cho);

   if(cho==1)
   {//ClearConsoleToColors(0,6);
       system("CLS");
       mapp();
       floydWarshall(graph);
       printf("\ndo you want to continue(1) or leave(0)");
       scanf("\n%d",&opt);

   }
   else if(cho==2)
   {//ClearConsoleToColors(10,14);
       system("CLS");
       activity();
       printf("\ndo you want to continue(1) or leave(0)");
       scanf("\n%d",&opt);
   }
   else if(cho==3)
   {
       exit(0);
   }

}while(opt==1);

    vector<int> orders = {0, 0, 0, 0, 0};
    vector<int> price = {20, 30, 40, 25, 15};
    int for_order,chooose=1;
    while(chooose==1){
    cout << "DO you want to place order enter 1"<< endl;
    cin >> chooose;
    if(chooose==1)
    {

    cout << "enter order no"<< endl;
    cin >> for_order;
    buy(for_order, orders);
    for (unsigned i=0; i<orders.size(); i++)
    std::cout << ' ' << orders.at(i);
  std::cout << '\n';

    }
    }

    rearrange(orders);

    return 0;
}

