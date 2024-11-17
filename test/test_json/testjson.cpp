#include "json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

//json序列化事例
string test01(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello world";

    string sendBuf = js.dump();

    //cout << sendBuf.c_str() << endl;
    return sendBuf;
}

string test02(){
    json js;
    // 添加数组
    js["id"] = {1,2,3,4,5};
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    //cout << js << endl;
    return js.dump();

}

string test03(){
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);   
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m; 
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;

    string sendBuf = js.dump();
    // cout<< sendBuf << endl;
    return sendBuf;
}

int main(){
    //test03();
    string recvBuf = test03();
    json jsBuf = json::parse(recvBuf);

    // cout << jsBuf["id"] << endl;
    // cout << jsBuf["msg"] << endl;
    // cout << jsBuf["name"] << endl;
    // //cout << jsBuf["msg_type"] << endl;

    // auto arr = jsBuf["id"];
    // cout << arr[1] << endl;;

    // auto msgjs = jsBuf["msg"];
    // cout << msgjs["liu shuo"] << endl;

    vector<int> vec = jsBuf["list"];
    map<int, string> m = jsBuf["path"];

    for (auto &i : m)
    {
        cout << i.first << "   " << i.second << endl;
    }
    

    return 0;
}