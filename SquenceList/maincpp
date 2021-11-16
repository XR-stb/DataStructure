#include <iostream>
#include "list.cpp"


int arr[] = {1,2,4,6,7,8,9};

int main(){
    List<int> L;
    L.init();
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) L.insert(arr[i],i);
    L.disp_List();
    std::cout << L.getlength() << std::endl;

    List<int> L2;
    L2.init();
    L2.insert(2,0);
    L2.insert(4,1);
    L2.insert(9,2);

    L2.disp_List();

    L.del_another(L2);//从L中删除 L2中出现的元素

    std::cout << L.getlength() << std::endl;

    system("pause");
    return 0;
}
