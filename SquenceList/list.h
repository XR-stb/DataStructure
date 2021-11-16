#ifndef LIST_H__
#define LIST_H__
#define MAX 1000

template<class T>
struct List{
    int length;
    T list[MAX];
    void init();
    void destroy();
    int getlength();
    T getElem(int idx);
    int locate(T loc);
    bool insert(T val, int idx);
    bool delElem(int idx);
    void disp_List();
    void del_another(List<T>& del_List);
};
#endif
