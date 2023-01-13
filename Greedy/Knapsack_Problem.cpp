#include"Headerfile.h"
class item
{
    public: 
    int value;
    int weight;
};

int knapsack(vector<int> v, vector<int> w, int n ,int W)
{
    vector<double> p_by_w;
    for (int i = 0; i < n; i++)
    {
        p_by_w[i] = v[i] / w[i];
    }

    sort(p_by_w.begin(),p_by_w.end());

    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
    
}
int main()
{
    int n;
    cin>> n;

    vector<int> 

    int max_w = 5;

    int res  = knapsack(val,weight,n,max_w);

    cout<< res << endl;


}