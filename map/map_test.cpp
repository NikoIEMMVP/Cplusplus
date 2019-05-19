ma
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace  std; 


void testMap()
{
   // map<int,int> map;
   // map.insert(make_pair(0,1));
   // map.insert(pair<int, int>(2,3));


   // map<string, string> dictMap;
   // dictMap.insert(make_pair("中国"， "China"));
   // dictMap.insert(make_pair("科技"， "Tech"));

   map<int, string> testMap;
   testMap[8] = "China";
   testMap[2] = "American";
   testMap[6] = "French";
   testMap[0] = "xiaoriben";
   testMap[0] = "Janpan";

   map<int, int> testMap1;
   testMap1[8] = 8;
   testMap1[2] = 2;
   testMap1[6] = 6;
   testMap1[0] = 1;
   testMap1[0]++;
   //testMap[0] = "Janpan";



   for(const auto& e : testMap1){
      cout << e.first << " " << e.second << endl;
   }

   // int key;
   // while(cin >> key){
   //    if(testMap.count(key)){
   //       cout << key << "--->" << testMap[key] << endl;
   //    }else{
   //       cout << "not bind the key !" << endl;
   //    }
   // }

   // if(testMap.find(key) != testMap.end()){
   //    cout << testMap[key] << endl;
   // }

}

void testMap1()
{
   multimap<int, string> testMap;
   // multimap ：不提供[]操作，key不唯一
   // testMap[8] = "China";
   // testMap[2] = "American";
   // testMap[6] = "French";
   // testMap[0] = "xiaoriben";

   // testMap.insert(make_pair(1,"中国"));
   // testMap.insert(make_pair(1,"美国"));
   // testMap.insert(make_pair(1,"法国"));
   // testMap.insert(make_pair(1,"西班牙"));
   // testMap.insert(make_pair(1,"德国"));
   // cout << testMap.count(1) << endl;
   // for(const auto& e : testMap){
   //    cout << e.first << "--->" << e.second << endl;
   // }

   testMap.insert(make_pair(1,"中国"));
   testMap.insert(make_pair(2,"美国"));
   testMap.insert(make_pair(3,"法国"));
   testMap.insert(make_pair(4,"西班牙"));
   testMap.insert(make_pair(5,"德国"));
   
   for(const auto& e : testMap){
      cout << e.first << "--->" << e.second << endl;
   }

   cout << endl;

   //lower_bound ：返回 >= key 第一个位置迭代器
   auto mit = testMap.lower_bound(2);
   cout << mit->first << " - " << mit->second << endl;

   //upper_bound ：返回 < key 第一个位置迭代器
   mit = testMap.upper_bound(3);
   cout << mit->first << " -- " << mit->second << endl;

}

void testSet()
{
   //sset<int> testSet;
   set<int,greater<int> >testSet;
   testSet.insert(1);
   testSet.insert(10);
   testSet.insert(18);
   testSet.insert(2);
   testSet.insert(3);
   testSet.insert(1);

   for(const auto& e : testSet){
      cout << e << endl;
   }
   
}




int main()
{
   testMap();
   //testMap1();
   //testSet();
   return 0;
}
