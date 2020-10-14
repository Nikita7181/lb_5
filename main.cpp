#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

using std::endl;
using std::cin;
using std::cout;
using std::string;

auto foo0(int a)
{
    cout << a << ", ";
}

void foo(std::pair<int,string> a)
{
    cout << a.first << "=" << a.second << ", ";
}

bool foo1(const std::pair<int, string> n)
{
    return ((n.first >=-1) && (n.first<=3));
}
int foo2(const std::pair<int, string> n)
{
    return n.first;
}
bool foo3(const int& value)
{
    return value == 0 ;
}
bool foo4(int a, int b)
{
    return a>b;
}

int main() {
    int r=0;
    cout << "Task1" << endl;
    cout << "#1" << endl;
    std::unordered_multimap<int,string> map({ {1, "town"}, {2, "town2"}, {3, "town3"}, {4, "town4"}, {4, "twon5"}, {5, "town6"}, {6,"town7"}, {7, "town8"} });
    map.insert(std::make_pair<int,string>(2,"town9"));
    map.insert(std::make_pair<int,string>(2,"town10"));
    map.insert(std::make_pair<int,string>(2,"town11"));
    map.insert(std::make_pair<int,string>(2,"town12"));
    std::for_each(map.begin(),map.end(), foo); cout << endl;
    cout << "#2" << endl;
    for (auto i = map.begin();i!=map.end();i++)
    {
        if (i->first == 4)
        {
             map.erase(i);
            r = 1;
        }
        {   if (r)
            break;
        }
    }
    std::for_each(map.begin(), map.end(), foo); cout << endl;
    cout << "#3" << endl;
    std::map<int,string> mt;
     for(auto i : map)
     {
        mt.insert(std::make_pair(i.first, i.second));
    }
    std::for_each(mt.begin(), mt.end(), foo); cout << endl;
    cout << "Task2" << endl;
    cout << "#1" << endl;
auto result = std::count_if(mt.begin(), mt.end(), foo1);
cout << result << endl;
cout << "#2" << endl;
    std::vector<int> t;
    std::transform(mt.begin(), mt.end(), std::back_inserter(t), foo2);
    std::for_each(t.begin(), t.end(), foo0);
    cout << endl;
cout << "Task3" << endl;
cout << "#1" << endl;
auto result1=std::find(t.begin(), t.end(), 6);
if (result1 == t.end())
{
    cout << "The number is not found" << endl;
} else
    {
    cout << "the number is found" << endl;
    }
cout << "#2" << endl;
std::replace_if(t.begin(), t.end(), foo3 ,-2 );
std::for_each(t.begin(), t.end(),foo0);
cout << endl;
cout << "#3" << endl;
std::sort(t.begin(), t.end(),foo4 );
std::for_each(t.begin(), t.end(), foo0);
cout << endl;
cout << "#4" << endl;
std::set <int> set1;
    for(auto i : t)
    {
       set1.insert(i);
    }
    std::for_each(set1.begin(),set1.end(),foo0);
return 0;
}
