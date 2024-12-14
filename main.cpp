#include <iostream>
using namespace std;
template <class T> class List{
    private:
        template <class G> class Cell{
            public:
            Cell<G> *next;
            T value;
            Cell(const G &v){
                this->value=v;
                next = nullptr;
            }
        };
        int lenght;
        Cell<T> *end;
        Cell<T> *begin;
    public: 
        List(){
            begin = end = nullptr;
            lenght = 0;
        }
        ~List(){
            Cell<T> *aux;
            while(begin!=nullptr){
                aux = begin;
                begin = begin->next;
                delete aux;
            }
        }
        bool append(const T &value){
            if(end == nullptr){
                begin = end = new Cell<T>(value);
                lenght++;
            }else{
                this->end->next = new Cell<T>(value);
                this->end = end->next;
                lenght++;
            }
            return 1;
        }
        bool put(const T &value){
            if(begin == nullptr){
                begin = end = new Cell<T>(value);
                lenght++;
            }else{
                Cell<T> *aux = new Cell<T>(value);
                aux->next = begin;
                lenght++;
                begin = aux;
            }
            return true;
        }
        bool putMd(const T &item, const int &posicao){
            Cell<T> *nvalue, *aux;
            aux = this->begin;
            for(int i = 0; i < posicao-1; i++){
                aux = aux->next;
            }
            nvalue =new Cell<T>(item);
            nvalue->next = aux->next;
            aux->next = nvalue;
            this->lenght++;
            return true;
        }
        bool pop(){
        if(this->begin == nullptr) { 
            return false; 
        } else { 
            if(this->begin->next == nullptr) {//só tem um elemento! 
                delete this->begin; 
                this->begin = this->end = nullptr; 
            } else { 
                Cell<T> *aux=this->begin, *aux1; 
                while(aux->next->next!= nullptr){  
                    aux=aux->next; 
                }
                aux1 = aux;
                delete end;
                this->end = aux1;
                aux->next = nullptr;
            } 
            this->lenght--; 
            return true; 
        }
        }
        bool popBg(){
            if(this->begin==nullptr){
                return false;
            }else{
                Cell<T> *aux;
                aux = this->begin;
                this->begin = this->begin->next;
                delete aux;
                lenght--;
                return true;
            }
            
        }
        bool popMd(int const &pos){
            if(pos<=lenght){
                Cell<T> *aux = this->begin, *srch;
                for(int i = 0; i < pos-1; i++){
                    aux = aux->next;
                    cout<<aux->next<<endl;
                }
                srch = aux->next;
                aux->next = aux->next->next; 
                if(aux->next == nullptr){
                    this->end = aux;
                    delete srch;
                    this->lenght--;  
                }
                return true;
            }else{
                return false;
            }
        }        
        void show(){
            Cell<T> *aux = this->begin;
            cout<<"[ ";
            while(aux != nullptr){
                cout<<aux->value<<" ";
                aux=aux->next;
            }
            cout<<"]"<<endl;
        }
        T showMd(int const &pos){
            if(pos<=lenght && pos >= 0){
                Cell<T> *aux;
                aux = this->begin;
                for(int i = 0; i < pos; i++){
                    aux=aux->next;
                }
                return aux->value;
            }else{
                cout<<"Not in the list"<<endl;
                return 0;
            }
            
        }
        int lenght(){
            return lenght;
        }
};


int main(){
    List<int> L;
    for(int i = 0; i<5; i++){
        L.append(i);
    }
    L.show();
    L.popMd(2);
    L.show();
    L.show();
    cout<<L.showMd(10);
    return 0;
}