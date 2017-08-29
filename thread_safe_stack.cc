#include<iostream>
#include<stack>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_mutex_t  m = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t w = PTHREAD_COND_INITIALIZER;
pthread_cond_t r = PTHREAD_COND_INITIALIZER;
int readers;
stack<int> stk;

int stk_top() {
	int val;
	pthread_mutex_lock(&m);
	while(readers==-1)
		pthread_cond_wait(&r,&m);
	readers++;
	pthread_mutex_unlock(&m);

	//shared res access
	if(stk.size()!=0)
		val = stk.top();
	else
		val =-1;
	cout <<"stk top is:" <<val<<endl;
	//shared res access
	

	pthread_mutex_lock(&m);
	readers--;
	if(readers==0)
		pthread_cond_signal(&w);
	pthread_mutex_unlock(&m);
	return val;
}

void stk_push(int val) {

	pthread_mutex_lock(&m);
	while(readers!=0)
		pthread_cond_wait(&w,&m);
	readers--;
	pthread_mutex_unlock(&m);

		stk.push(val); //shared res access
	cout <<"stk pushed :" <<val<<endl;

	pthread_mutex_lock(&m);
	readers++;
	pthread_mutex_unlock(&m);

	pthread_cond_broadcast(&r);
	pthread_cond_signal(&w);
	
	return;
}

void stk_pop(){

	pthread_mutex_lock(&m);
	while(readers!=0)
		pthread_cond_wait(&w,&m);
	readers--;
	pthread_mutex_unlock(&m);	
	
	if(stk.size()!=0)
		stk.pop();

	cout <<"stk popped:"<<endl;

	pthread_mutex_lock(&m);
	readers++;
	pthread_mutex_unlock(&m);

	pthread_cond_broadcast(&r);
	pthread_cond_signal(&w);

	return;
}

void* readf (void * arg) {
	for(int i=0;i<5;i++){
		sleep(10*(rand()%3));
		stk_top();			
	}
	return 0;
}
void* writef (void * arg) {
	for(int i=0;i<5;i++){
		sleep(10*(rand()%3));
		if(i%2)
			stk_push(i);
		else
			stk_pop();			
	}
	return 0;
}
int main(){
	pthread_t writer[4];
	pthread_t reader[4];

	for(int i=0;i<4;i++)
		pthread_create(&reader[i],NULL,readf,NULL);

	for(int i=0;i<4;i++)
		pthread_create(&writer[i],NULL,writef,NULL);

	for(int i=0;i<4;i++) {
		pthread_join(writer[i],NULL);
		pthread_join(reader[i],NULL);
	}
	cout << "main thread exiting"<<endl;
	return 0;
}
