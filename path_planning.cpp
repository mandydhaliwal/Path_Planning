#include <iostream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 struct Node
{
public:
	int container = 0;
	int weight[4] = { 10,10,10,10 };
	int came_from = -1;
};
struct location
{
public:
	int x, y;
};
struct node
{double priority;
	location info;
	int path;
	struct node *link;
};
/*
 * Class Priority Queue
 */
class p_queue
{
    private:
        node *front;
    public:
        p_queue()
        {
            front = nullptr;
        }
        /*
         * Insert into Priority Queue
         */
        void insert(location item, double priority, int path)
        {
            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            tmp->path=path;
            if (front == nullptr || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != nullptr && q->link->priority <= priority)
                    q=q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
		tmp=NULL;q=NULL;free(tmp);free(q);
        }
        /*
         * Delete from Priority Queue
         */
        location del()
        {
            node *tmp;location t;
            if(front == nullptr)
                cout<<"Queue Underflow\n";
            else
            {
                tmp = front;
                cout<<"Deleted item is: "<<tmp->priority<<endl;
                 t=tmp->info;
                front = front->link;
                free(tmp);
            }
            return t;
        }
        int get_path()
        {
            node *tmp;int t;
            if(front == nullptr)
               {
                 cout<<"Queue Underflow\n";
                 return -1;
               }
            else
            {
                tmp = front;
               // cout<<"Deleted item is: "<<tmp->priority<<" and "<<tmp->path<<endl;
                 t=tmp->path;
                front = front->link;
                free(tmp);
            }
            return t;
        }
        /*
         * Print Priority Queue
         */
        void display()
        {
            node *ptr;
            ptr = front;
            if (front == nullptr)
                cout<<"Queue is empty\n";
            else
            {	cout<<"Queue is :\n";
                cout<<"Priority       Item\n";
                while(ptr != nullptr)
                {
                    cout<<ptr->priority<<"                 "<<ptr->path<<endl;
                    ptr = ptr->link;
                }
            }
        }
        int empty()
        {
            if(front==nullptr)
                return 1;
            else
                return 0;
        }
};
location neighbours(location l , int p)
{

	location k[4];
	k[0].x = l.x;
	k[0].y = l.y - 1;
	k[1].x = l.x + 1;
	k[1].y = l.y;
	k[2].x = l.x;
	k[2].y = l.y + 1;
	k[3].x = l.x - 1;
	k[3].y = l.y;
	return k[p];
}
void dijkstra_search(location start, location goal)
{
	Node arena[5][7];
	arena[0][0].weight[0]=10;	arena[0][0].weight[1]=20;	arena[0][0].weight[2]=28;	arena[0][0].weight[3]=1000;
	
	arena[0][1].weight[0]=10;	arena[0][1].weight[1]=17;	arena[0][1].weight[2]=27;	arena[0][1].weight[3]=20;
	
	arena[0][2].weight[0]=10;	arena[0][2].weight[1]=17;	arena[0][2].weight[2]=1000;	arena[0][2].weight[3]=17;
	
	arena[0][3].weight[0]=1000;	arena[0][3].weight[1]=17;	arena[0][3].weight[2]=1000;	arena[0][3].weight[3]=17;
	
	arena[0][4].weight[0]=10;	arena[0][4].weight[1]=17;	arena[0][4].weight[2]=1000;	arena[0][4].weight[3]=17;
	
	arena[0][5].weight[0]=10;	arena[0][5].weight[1]=20;	arena[0][5].weight[2]=27;	arena[0][5].weight[3]=17;
	
	arena[0][6].weight[0]=10;	arena[0][6].weight[1]=1000;	arena[0][6].weight[2]=28;	arena[0][6].weight[3]=20;

		arena[1][0].weight[0]=28;	arena[1][0].weight[1]=24;	arena[1][0].weight[2]=27;	arena[1][0].weight[3]=1000;
	
	arena[1][1].weight[0]=27;	arena[1][1].weight[1]=18;	arena[1][1].weight[2]=1000;	arena[1][1].weight[3]=24;
	
	arena[1][2].weight[0]=1000;	arena[1][2].weight[1]=20;	arena[1][2].weight[2]=10;	arena[1][2].weight[3]=18;
	
	arena[1][3].weight[0]=1000;	arena[1][3].weight[1]=20;	arena[1][3].weight[2]=1000;	arena[1][3].weight[3]=20;
	
	arena[1][4].weight[0]=1000;	arena[1][4].weight[1]=18;	arena[1][4].weight[2]=10;	arena[1][4].weight[3]=20;
	
	arena[1][5].weight[0]=27;	arena[1][5].weight[1]=24;	arena[1][5].weight[2]=1000;	arena[1][5].weight[3]=18;
	
	arena[1][6].weight[0]=28;	arena[1][6].weight[1]=1000;	arena[1][6].weight[2]=1000;	arena[1][6].weight[3]=24;
	
	
	arena[2][0].weight[0]=27;	arena[2][0].weight[1]=17;	arena[2][0].weight[2]=15;	arena[2][0].weight[3]=1000;
	
	arena[2][1].weight[0]=1000;	arena[2][1].weight[1]=16;	arena[2][1].weight[2]=1000;	arena[2][1].weight[3]=17;
	
	arena[2][2].weight[0]=10;	arena[2][2].weight[1]=33;	arena[2][2].weight[2]=1000;	arena[2][2].weight[3]=16;
	
	arena[2][3].weight[0]=1000;	arena[2][3].weight[1]=33;	arena[2][3].weight[2]=10;	arena[2][3].weight[3]=33;
	
	arena[2][4].weight[0]=10;	arena[2][4].weight[1]=16;	arena[2][4].weight[2]=1000;	arena[2][4].weight[3]=33;
	
	arena[2][5].weight[0]=1000;	arena[2][5].weight[1]=17;	arena[2][5].weight[2]=1000;	arena[2][5].weight[3]=16;
	
	arena[2][6].weight[0]=1000;	arena[2][6].weight[1]=1000;	arena[2][6].weight[2]=15;	arena[2][6].weight[3]=17;
	
		arena[3][0].weight[0]=15;	arena[3][0].weight[1]=1000;	arena[3][0].weight[2]=1000;	arena[3][0].weight[3]=1000;
	
	arena[3][1].weight[0]=1000;	arena[3][1].weight[1]=1000;	arena[3][1].weight[2]=1000;	arena[3][1].weight[3]=1000;
	
	arena[3][2].weight[0]=1000;	arena[3][2].weight[1]=1000;	arena[3][2].weight[2]=1000;	arena[3][2].weight[3]=1000;
	
	arena[3][3].weight[0]=10;	arena[3][3].weight[1]=1000;	arena[3][3].weight[2]=10;	arena[3][3].weight[3]=1000;
	
	arena[3][4].weight[0]=1000;	arena[3][4].weight[1]=1000;	arena[3][4].weight[2]=1000;	arena[3][4].weight[3]=1000;
	
	arena[3][5].weight[0]=1000;	arena[3][5].weight[1]=1000;	arena[3][5].weight[2]=1000;	arena[3][5].weight[3]=1000;
	
	arena[3][6].weight[0]=15;	arena[3][6].weight[1]=1000;	arena[3][6].weight[2]=1000;	arena[3][6].weight[3]=1000;
	
		arena[4][0].weight[0]=1000;	arena[4][0].weight[1]=1000;	arena[4][0].weight[2]=1000;	arena[4][0].weight[3]=1000;
	
	arena[4][1].weight[0]=1000;	arena[4][1].weight[1]=1000;	arena[4][1].weight[2]=1000;	arena[4][1].weight[3]=1000;
	
	arena[4][2].weight[0]=1000;	arena[4][2].weight[1]=30;	arena[4][2].weight[2]=1000;	arena[4][2].weight[3]=1000;
	
	arena[4][3].weight[0]=10;	arena[4][3].weight[1]=30;	arena[4][3].weight[2]=1000;	arena[4][3].weight[3]=30;
	
	arena[4][4].weight[0]=1000;	arena[4][4].weight[1]=1000;	arena[4][4].weight[2]=1000;	arena[4][4].weight[3]=30;
	
	arena[4][5].weight[0]=1000;	arena[4][5].weight[1]=1000;	arena[4][5].weight[2]=1000;	arena[4][5].weight[3]=1000;
	
	arena[4][6].weight[0]=1000;	arena[4][6].weight[1]=1000;	arena[4][6].weight[2]=1000;	arena[4][6].weight[3]=1000;
    double cost_so_far[5][7];
	for (int k = 0; k < 7; k++)
		for (int j = 0; j < 5; j++)
			cost_so_far[j][k] = -1;
	p_queue frontier;
	frontier.insert(start, 0,-1);
	int cf_dir[4] = { 2,3,0,1 };
	arena[start.y][start.x].came_from = -2;
	cost_so_far[start.y][start.x] = 0;

	while (!(frontier.empty())) {
		location current = frontier.del();

/*
->Giving Error , path going out of arena*/
if(current.x==goal.x&&current.y==goal.y)
          break;

			for (int i = 0; i < 4; i++) {
                    location next = neighbours(current,i);
				if (next.x == -1 || next.x == 7)
					continue;
				if (next.y == -1 || next.y == 5)
					continue;


				double new_cost = cost_so_far[current.y][current.x] + arena[current.y][current.x].weight[i];
				if (cost_so_far[next.y][next.x] == -1 || new_cost < cost_so_far[next.y][next.x])
				{

					cost_so_far[next.y][next.x] = new_cost;

					arena[next.y][next.x].came_from = i;
					frontier.insert(next, new_cost,-1);
					frontier.display();

				}
			}
	}

	int path[35];
	for (int i = 0; i < 35; i++)
		path[i] = -1;
	int p[35];
	for (int i = 0; i < 35; i++)
		p[i] = -1;
	int i = 35;
	location current = goal;
	p_queue path_t;
	while (--i) {
        //if(arena[current.y][current.x].weight[0]==0||arena[current.y][current.x].weight[1]==0||arena[current.y][current.x].weight[2]==0||arena[current.y][current.x].weight[3]==0)
          //  continue;

		path_t.insert(current,i,arena[current.y][current.x].came_from);
		path[i]=arena[current.y][current.x].came_from;
		if (path[i] == 0)
			current.y = current.y + 1;
		if (path[i] == 1)
			current.x = current.x - 1;
		if (path[i] == 2)
			current.y = current.y - 1;
		if (path[i] == 3)
			current.x = current.x + 1;
        if(current.x==start.x&&current.y==start.y)
            break;

	}
	//path.push_back(start); // optional

	/*for (int k = 27; k > -1; k--)
	{
		if (path[k] == -1)
			continue;
		p[27 - k] = path[k];
	}*/
	for (int j = 0; j < 5; j++)
		{for(int k=0;k<7;k++)
            cout<<arena[j][k].came_from<<" -> ";
            cout<<endl;
            }
    cout<<endl;
    cout<<endl;
    path_t.display();
    cout<<endl<<"Start ";
    while(!path_t.empty())
        cout<<path_t.get_path()<<" ->";
    cout<<" GOAL"<<endl;

}
int main()
{
    location s = { 4,4};
	location g = {0,0};
	dijkstra_search(s, g);
return 0;
}
