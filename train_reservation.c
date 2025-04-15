#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
//Function Prototypes
void train_writ();
void book_ticket();
void counter_details();
void add_train();
void read_data();
void day(short ch);
void print_det();
//Global Keywords
int tot_train = 0;
int sno=1;
int ticket_no;
struct train{
	int rno;
	int train_no;
	char train_name[25];
	char dept[25];
	char dept_time[6];
	char dest_time[6];
	char arrival[25];
	float distance;
	int ac;
	int ac_b[3];
	int ac_s[2];
	float ac_fare;
	int pr;
	int pr_b[3];
	int pr_s[2];
	float pr_fare;
	int na;
	int na_avail;
	float na_fare;
	int tatkal_avail;
	float tatkal_fare;
	struct train *next;
}*head,*d[6];
struct count{
	int ac;
	int pr;
	int na;
	int tatkal;
	int senior_citizen;
	int pregnant_women;
	int women;
	int total_ticket;
	float ac_fare;
	float pr_fare;
	float na_fare;
	float tatkal_fare;
	unsigned long int total_fare;
	int waiting;
}z[6];
int main(){
	read_data();
	short ch;
	while(1){
		printf("\n\n\t1.Add Train\n\t2.Book Ticket\n\t3.Counter Details\n\t4.Exit");
		printf("\nEnter your Choice : ");
		scanf("%hd",&ch);
		switch(ch){
			case 1:{
				add_train();
				break;
			}
			case 2:{
				book_ticket();
				break;
			}
			case 3:{
				counter_details();
				break;
			}
			case 4:{
				exit(1);
				break;
			}
			default:
				printf("\n\a***Enter Correct Choice***");
		}
	}
}
void train_writ(){
	FILE *fp;
	fp=fopen("total.txt","w");
	fprintf(fp,"%d %d %d",tot_train,sno,ticket_no);
	fclose(fp);
}
void counter_details(){
	short i;
	unsigned long int fare=0,tickets=0,ac=0,pr=0,na=0,tat=0,wait=0,acf=0,prf=0,naf=0,tatf=0,sc=0,pw=0,w=0;
	for(i=0;i<6;i++){
		printf("\n*****************************************\n");
		printf("\nDay : %hd",i+1);
		printf("\nAC Seats Booked 		: %d",z[i].ac);
		printf("\nPremium Seats Booked  		: %d",z[i].pr);
		printf("\nNON-AC Seats Booked 		: %d",z[i].na);
		printf("\nTatkal Seats Booked   		: %d",z[i].tatkal);
		printf("\nFare Collected in AC  		: %.2f",z[i].ac_fare);
		printf("\nFare Collected in Premium  	: %.2f",z[i].pr_fare);
		printf("\nFare Collected in Non-AC  	: %.2f",z[i].na_fare);
		printf("\nFare Collected in Tatkal  	: %.2f",z[i].tatkal_fare);
		printf("\n\nTotal Tickets Collected for Day %hd : %d",i+1,z[i].total_ticket);
		printf("\n\nTotal Fare Collected for Day %hd : %lu",i+1,z[i].total_fare);
		printf("\n\nPregnant Woman		 		: %d",z[i].pregnant_women);
		printf("\nWomen+45 Years				: %d",z[i].women);
		printf("\nSenior Citizen				: %d",z[i].senior_citizen);
		printf("\nWaiting					: %d",z[i].waiting);
		tickets+=z[i].total_ticket;
		fare+=z[i].total_fare;
		ac+=z[i].ac;
		pr+=z[i].pr;
		na+=z[i].na;
		tat+=z[i].tatkal;
		wait+=z[i].waiting;
		acf+=z[i].ac_fare;
		prf+=z[i].pr_fare;
		naf+=z[i].na_fare;
		tatf+=z[i].tatkal_fare;
		sc+=z[i].senior_citizen;
		w+=z[i].women;
		pw+=z[i].pregnant_women;
	}
	printf("\n*****************************************\n");
	printf("\n*****************************************\n");
	printf("\nNumber of Tickets Sold  		: %lu",tickets);
	printf("\nAC Seats Booked 		        : %lu",ac);
	printf("\nPremium Seats Booked   			: %lu",pr);
	printf("\nNON-AC Seats Booked 	 		: %lu",na);
	printf("\nTatkal Seats Booked    			: %lu",tat);
	printf("\nWaiting Seats Booked   			: %lu",wait);
	printf("\n*****************************************\n");
	printf("\nTotal Fare Collected		      	        : %lu",fare);
	printf("\nAC Fare				 		: %lu",acf);
	printf("\nPremium Fare			 		: %lu",prf);
	printf("\nNon-AC Fare			 		: %lu",naf);
	printf("\nTatkal Fare			 		: %lu",tatf);
	printf("\n*****************************************\n");
	printf("\nPregnant Woman			        : %lu",pw);
	printf("\nWomen +45 Years			    	: %lu",w);
	printf("\nSenior Citizen		 		: %lu",sc);
}
void print_det(){
	struct train *add;
	add=head;
	if(add==NULL){
		printf("\n\nTrains not not available now...\n\n");
		return;
	}
	printf("\nRoute_No Train_No Train_Name                Departure                 Dept_time Dest_time     Arrival                   Distance\n");
	printf("=================================================================================================================================\n");
	while(add->next!=NULL){
		printf("%-8d %-8d %-25s %-25s %-11s %-11s %-25s %f \n",add->rno,add->train_no,add->train_name,add->dept,add->dept_time,add->dest_time,add->arrival,add->distance);
		add=add->next;
	}
	printf("%-8d %-8d %-25s %-25s %-11s %-11s %-25s %f \n",add->rno,add->train_no,add->train_name,add->dept,add->dept_time,add->dest_time,add->arrival,add->distance);
}
void day(short ch){
	//k - train route / s = loop iteration / l = type of ticket / p - passenger
	short k,s=1,l,p,i,y;
	struct train *add;
	add=d[ch];
	while(s){
		printf("\nEnter Route No : ");
		scanf("%hd",&k);
		if(k<=0 || k>=sno)
			printf("\n\n\aEnter Correct Route No");
		else
			s=0;	
	}
	s=1;
	while(add->next!=NULL){
		if(add->rno == k)
			break;
		add=add->next;
	}
	if(!(add->rno == k)){
		printf("\n\aEntered Route Not Found");
		return;
	}
	int c = add->ac_b[0]+add->ac_b[1]+add->ac_b[2]+add->ac_s[0]+add->ac_s[1];
	int v = add->pr_b[0]+add->pr_b[1]+add->pr_b[2]+add->pr_s[0]+add->pr_s[1];
	while(s){
		printf("\n 1. AC Berths Availability : %d",c);
		printf("\n 2. Premium Availability   : %d",v);
		printf("\n 3. Non-Ac Availability    : %d",add->na_avail);
		printf("\n 4. Tatkal Availability    : %d",add->tatkal_avail);
		printf("\nEnter your Choice : ");
		scanf("%hd",&l);
		if(l<=0 || l>=5)
			printf("\n\n\aEnter Correct Type No");
		else
			s=0;
	}
	s=1;
	while(s){
		printf("\nEnter how many passenger (Limited 5) : ");
		scanf("%hd",&p);
		if(p<=0 || p>=6)
			printf("\n\n\a5 passenger per Ticket");
		else{
			if(l==1){//AC
				float fare=0;
				printf("\n\nEnter Passenger Details ");
				for(i=0;i<p;i++){
					printf("\nPassenger %hd : \n",i+1);
					short age,m,n=1;
					char gender;
					printf("\nEnter Age : ");
					scanf("%hd",&age);
					while(n){
						printf("\n 1. Male \n 2. Female\t");
						scanf("%hd",&m);
						if(m==1 || m==2)
							n=0;
						else
							printf("\n\aEnter Correctly!");
					}
					if(m==1)
						gender='M';
					else
						gender='F';
					if(age<5){
						if(add->ac_b[0]>0){
							add->ac_b[0]-=1;
							printf("\nBooked in Lower Berth");
						}
						else if(add->ac_s[0]>0){
							add->ac_s[0]-=1;
							printf("\nBooked in Side Lower Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
					}
					else if(age>=5 && age<=12){
						if(add->ac_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->ac_b[1]-=1;
						}	
						else if(add->ac_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->ac_s[1]-=1;
						}	
						else if(add->ac_b[2]>0){
							add->ac_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=(add->ac_fare / 2);
					}
					else if(age>=13 && age<=18){
						if(add->ac_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->ac_b[1]-=1;
						}	
						else if(add->ac_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->ac_s[1]-=1;
						}	
						else if(add->ac_b[2]>0){
							add->ac_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->ac_fare;
					}
					else if(gender == 'F' && age>18){
						printf("\nIs Pregnant Woman ? 1.Yes 2.NO ");
						scanf("%hd",&y);
						if(y==1){
							z[ch].pregnant_women+=1;
							fare+=add->ac_fare;
							if(add->ac_b[0]>0){
								add->ac_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->ac_s[0]>0){
								add->ac_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
						}
						else if(age<=45){
							if(add->ac_b[1]>0){
								printf("\nBooked in Middle Berth");
								add->ac_b[1]-=1;
							}	
							else if(add->ac_s[1]>0){
								printf("\nBooked in Side Upper Berth");
								add->ac_s[1]-=1;
							}	
							else if(add->ac_b[2]>0){
								add->ac_b[2]-=1;
								printf("\nBooked in Upper Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->ac_fare;
						}
						else if(age>45 && age<60){
							if(add->ac_b[0]>0){
								add->ac_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->ac_s[0]>0){
								add->ac_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->ac_fare;
							z[ch].women+=1;
						}
						else {
							if(add->ac_b[0]>0){
								add->ac_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->ac_s[0]>0){
								add->ac_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->ac_fare;
							z[ch].senior_citizen+=1;
						}	
					}
					else if(gender=='M' && age<60){
						if(add->ac_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->ac_b[1]-=1;
						}	
						else if(add->ac_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->ac_s[1]-=1;
						}	
						else if(add->ac_b[2]>0){
							add->ac_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->ac_fare;
					}
					else if(age>=60){
						if(add->ac_b[0]>0){
							add->ac_b[0]-=1;
							printf("\nBooked in Lower Berth");
						}
						else if(add->ac_s[0]>0){
							add->ac_s[0]-=1;
							printf("\nBooked in Side Lower Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->ac_fare;
						z[ch].senior_citizen+=1;
					}
				}
				printf("\n\nTotal Fare to be paid : Rs.%.2f/-",fare);
				z[ch].ac=z[ch].ac+p;
				z[ch].total_ticket=z[ch].total_ticket+p;
				z[ch].ac_fare=z[ch].ac_fare+fare;
				z[ch].total_fare=z[ch].total_fare+fare;
			}
			else if(l==2){ //Premium
				float fare=0;
				printf("\n\nEnter Passenger Details ");
				for(i=0;i<p;i++){
					printf("\nPassenger %hd : \n",i+1);
					short age,m,n=1;
					char gender;
					printf("\nEnter Age : ");
					scanf("%hd",&age);
					while(n){
						printf("\n 1. Male \n 2. Female\t");
						scanf("%hd",&m);
						if(m==1 || m==2)
							n=0;
						else
							printf("\n\aEnter Correctly!");
					}
					if(m==1)
						gender='M';
					else
						gender='F';
					if(age<5){
						if(add->pr_b[0]>0){
							add->pr_b[0]-=1;
							printf("\nBooked in Lower Berth");
						}
						else if(add->pr_s[0]>0){
							add->pr_s[0]-=1;
							printf("\nBooked in Side Lower Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
					}
					else if(age>=5 && age<=12){
						if(add->pr_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->pr_b[1]-=1;
						}	
						else if(add->pr_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->pr_s[1]-=1;
						}	
						else if(add->pr_b[2]>0){
							add->pr_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=(add->pr_fare / 2);
					}
					else if(age>=13 && age<=18){
						if(add->pr_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->pr_b[1]-=1;
						}	
						else if(add->pr_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->pr_s[1]-=1;
						}	
						else if(add->pr_b[2]>0){
							add->pr_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->pr_fare;
					}
					else if(gender == 'F' && age>18){
						printf("\nIs Pregnant Woman ? 1.Yes 2.NO ");
						scanf("%hd",&y);
						if(y==1){
							z[ch].pregnant_women+=1;
							fare+=add->pr_fare;
							if(add->pr_b[0]>0){
								add->pr_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->pr_s[0]>0){
								add->pr_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
						}
						else if(age<=45){
							if(add->pr_b[1]>0){
								printf("\nBooked in Middle Berth");
								add->pr_b[1]-=1;
							}	
							else if(add->pr_s[1]>0){
								printf("\nBooked in Side Upper Berth");
								add->pr_s[1]-=1;
							}	
							else if(add->pr_b[2]>0){
								add->pr_b[2]-=1;
								printf("\nBooked in Upper Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->pr_fare;
						}
						else if(age>45 && age<60){
							if(add->pr_b[0]>0){
								add->pr_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->pr_s[0]>0){
								add->pr_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->pr_fare;
							z[ch].women+=1;
						}
						else {
							if(add->pr_b[0]>0){
								add->pr_b[0]-=1;
								printf("\nBooked in Lower Berth");
							}
							else if(add->pr_s[0]>0){
								add->pr_s[0]-=1;
								printf("\nBooked in Side Lower Berth");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->pr_fare;
							z[ch].senior_citizen+=1;
						}	
					}
					else if(gender=='M' && age<60){
						if(add->pr_b[1]>0){
							printf("\nBooked in Middle Berth");
							add->pr_b[1]-=1;
						}	
						else if(add->pr_s[1]>0){
							printf("\nBooked in Side Upper Berth");
							add->pr_s[1]-=1;
						}	
						else if(add->pr_b[2]>0){
							add->pr_b[2]-=1;
							printf("\nBooked in Upper Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->pr_fare;
					}
					else if(age>=60){
						if(add->pr_b[0]>0){
							add->pr_b[0]-=1;
							printf("\nBooked in Lower Berth");
						}
						else if(add->pr_s[0]>0){
							add->pr_s[0]-=1;
							printf("\nBooked in Side Lower Berth");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->pr_fare;
						z[ch].senior_citizen+=1;
					}
				}
				printf("\n\nTotal Fare to be paid : Rs.%.2f/-",fare);
				z[ch].pr=z[ch].pr+p;
				z[ch].total_ticket=z[ch].total_ticket+p;
				z[ch].pr_fare=z[ch].pr_fare+fare;
				z[ch].total_fare=z[ch].total_fare+fare;
			}
			else if(l==3){//NON AC
				float fare=0;
				printf("\n\nEnter Passenger Details ");
				for(i=0;i<p;i++){
					printf("\nPassenger %hd : \n",i+1);
					short age,m,n=1;
					char gender;
					printf("\nEnter Age : ");
					scanf("%hd",&age);
					while(n){
						printf("\n 1. Male \n 2. Female\t");
						scanf("%hd",&m);
						if(m==1 || m==2)
							n=0;
						else
							printf("\n\aEnter Correctly!");
					}
					if(m==1)
						gender='M';
					else
						gender='F';
					if(age<5){
						if(add->na_avail>0){
							add->na_avail-=1;
							printf("\n Seat Booked ");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
					}
					else if(age>=5 && age<=12){
						if(add->na_avail>0){
							add->na_avail-=1;
							printf("\n Seat Booked ");
						}	
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=(add->na_fare / 2);
					}
					else if(age>=13 && age<=18){
						if(add->na_avail>0){
							add->na_avail-=1;
							printf("\n Seat Booked ");
						}	
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->na_fare;
					}
					else if(gender == 'F' && age>18){
						printf("\nIs Pregnant Woman ? 1.Yes 2.NO ");
						scanf("%hd",&y);
						if(y==1){
							z[ch].pregnant_women+=1;
							fare+=add->na_fare;
							if(add->na_avail>0){
								add->na_avail-=1;
								printf("\n Seat Booked ");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
						}
						else if(age<=45){
							if(add->na_avail>0){
								add->na_avail-=1;
								printf("\n Seat Booked ");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->na_fare;
						}
						else if(age>45 && age<60){
							if(add->na_avail>0){
								add->na_avail-=1;
								printf("\n Seat Booked ");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->na_fare;
							z[ch].women+=1;
						}
						else {
							if(add->na_avail>0){
								add->na_avail-=1;
								printf("\n Seat Booked ");
							}
							else{
								z[ch].waiting+=1;
								printf("\nIn Waiting List");
							}
							fare+=add->na_fare;
							z[ch].senior_citizen+=1;
						}	
					}
					else if(gender=='M' && age<60){
						if(add->na_avail>0){
							add->na_avail-=1;
							printf("\n Seat Booked ");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->na_fare;
					}
					else if(age>=60){
						if(add->na_avail>0){
							add->na_avail-=1;
							printf("\n Seat Booked ");
						}
						else{
							z[ch].waiting+=1;
							printf("\nIn Waiting List");
						}
						fare+=add->na_fare;
						z[ch].senior_citizen+=1;
					}
				}
				printf("\n\nTotal Fare to be paid : Rs.%.2f/-",fare);
				z[ch].na=z[ch].na+p;
				z[ch].total_ticket=z[ch].total_ticket+p;
				z[ch].na_fare=z[ch].na_fare+fare;
				z[ch].total_fare=z[ch].total_fare+fare;
			}
			else{ //TATKAL
				if(add->tatkal_avail>=p){
					float fare=0;
					printf("\n\nEnter Passenger Details ");
					for(i=0;i<p;i++){
						printf("\nPassenger %hd : \n",i+1);
						short age,m,n=1;
						char gender;
						printf("\nEnter Age : ");
						scanf("%hd",&age);
						while(n){
							printf("\n 1. Male \n 2. Female\t");
							scanf("%hd",&m);
							if(m==1 || m==2)
								n=0;
							else
								printf("\n\aEnter Correctly!");
						}
						if(m==1)
							gender='M';
						else
							gender='F';
						if(age<5){
							add->tatkal_avail-=1;
							printf("\n Seat Booked ");
						}
						else if(age>=5 && age<=12){
							add->tatkal_avail-=1;
							printf("\n Seat Booked ");
							fare+=(add->tatkal_fare / 2);
						}
						else if(age>=13 && age<=18){
							add->tatkal_avail-=1;
							printf("\n Seat Booked ");
							fare+=add->tatkal_fare;
						}
						else if(gender == 'F' && age>18){
							printf("\nIs Pregnant Woman ? 1.Yes 2.NO ");
							scanf("%hd",&y);
							if(y==1){
								z[ch].pregnant_women+=1;
								fare+=add->tatkal_fare;
								add->tatkal_avail-=1;
								printf("\n Seat Booked ");
							}
							else if(age<=45){
								add->tatkal_avail-=1;
								printf("\n Seat Booked ");
								fare+=add->tatkal_fare;
							}
							else if(age>45 && age<60){
								add->tatkal_avail-=1;
								printf("\n Seat Booked ");	
								fare+=add->tatkal_fare;
								z[ch].women+=1;
							}
							else {
								add->tatkal_avail-=1;
								printf("\n Seat Booked ");
								fare+=add->tatkal_fare;
								z[ch].senior_citizen+=1;
							}	
						}
						else if(gender=='M' && age<60){
							add->tatkal_avail-=1;
							printf("\n Seat Booked ");
							fare+=add->tatkal_fare;
						}
						else if(age>=60){
							add->tatkal_avail-=1;
							printf("\n Seat Booked ");
							fare+=add->tatkal_fare;
							z[ch].senior_citizen+=1;
						}
					}
					printf("\n\nTotal Fare to be paid : Rs.%.2f/-",fare);
					z[ch].tatkal=z[ch].tatkal+p;
					z[ch].total_ticket=z[ch].total_ticket+p;
					z[ch].tatkal_fare=z[ch].tatkal_fare+fare;
					z[ch].total_fare=z[ch].total_fare+fare;
				}
				else{
					printf("\n\aSeat not available");
					return;
				}
			}
			printf("\nYour Ticket Number : %d ",ticket_no++);
			printf("\nThank You for Booking");
			train_writ();
			s=0;
			FILE *f,*a;
			struct train *tem;
			switch(ch){
				case 0:{
					f=fopen("count_day1.txt","w");
					a=fopen("day_1.txt","w");
					tem=d[0];
					break;
				}
				case 1:{
					f=fopen("count_day2.txt","w");
					a=fopen("day_2.txt","w");
					tem=d[1];
					break;
				}
				case 2:{
					f=fopen("count_day3.txt","w");
					a=fopen("day_3.txt","w");
					tem=d[2];
					break;
				}
				case 3:{
					f=fopen("count_day4.txt","w");
					a=fopen("day_4.txt","w");
					tem=d[3];
					break;
				}	
				case 4:{
					f=fopen("count_day5.txt","w");
					a=fopen("day_5.txt","w");
					tem=d[4];
					break;
				}
				case 5:{
					f=fopen("count_day6.txt","w");
					a=fopen("day_6.txt","w");
					tem=d[5];
					break;
				}
			}
			fprintf(f,"%d %d %d %d %d %d %d %d %f %f %f %f %lu %d",z[ch].ac,z[ch].pr,z[ch].na,z[ch].tatkal,z[ch].senior_citizen,z[ch].pregnant_women,z[ch].women,z[ch].total_ticket,z[ch].ac_fare,z[ch].pr_fare,z[ch].na_fare,z[ch].tatkal_fare,z[ch].total_fare,z[ch].waiting);
			fclose(f);
			while(tem!=NULL){
				fprintf(a,"%-8d %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8f %-8f %-8d \n",tem->rno,tem->ac,tem->ac_b[0],tem->ac_b[1],tem->ac_b[2],tem->ac_s[0],tem->ac_s[1],tem->ac_fare,tem->pr,tem->pr_b[0],tem->pr_b[1],tem->pr_b[2],tem->pr_s[0],tem->pr_s[1],tem->pr_fare,tem->na,tem->na_avail,tem->na_fare,tem->tatkal_fare,tem->tatkal_avail);
				tem=tem->next;
			}
			fclose(a);
		}
	}
	printf("\nTicket Booked Successfully...");
}
void book_ticket(){
	short ch;
	printf("\n\n\t 1. Day 1\n\t 2. Day 2\n\t 3. Day 3\n\t 4. Day 4\n\t 5. Day 5\n\t 6. Day 6\n\t 7. Back\n\nEnter your choice : ");
	scanf("%hd",&ch);
	if(ch==7)
		return ;
	if(ch<=0 || ch>7){
		printf("\n\n\aInvalid Choice...\n");
		return;
	}
	print_det();
	day(ch-1);
}
void add_train(){
	FILE *g,*h;
	short i,j;
	struct train *add = (struct train *) malloc(sizeof(struct train));
	add->rno=sno;
	printf("\nEnter Train Number : ");
	scanf("%d",&add->train_no);
	fflush(stdin);
	printf("\nEnter Train Name : ");
	scanf("%[^\n]",add->train_name);
	fflush(stdin);
	printf("\nEnter Departure Route : ");
	scanf("%[^\n]",add->dept);
	fflush(stdin);
	printf("\nEnter Departure Time : ");
	scanf("%[^\n]",add->dept_time);
	fflush(stdin);
	printf("\nEnter Destination Time : ");
	scanf("%[^\n]",add->dest_time);
	fflush(stdin);
	printf("\nEnter Arrival Route : ");
	scanf("%[^\n]",add->arrival);
	printf("\nEnter Distance : ");
	scanf("%f",&add->distance);
	printf("\nEnter how many coaches in AC : ");
	scanf("%d",&add->ac);
	add->ac_b[0]=18 * add->ac;
	add->ac_b[1]=18*add->ac;
	add->ac_b[2]=18*add->ac;
	add->ac_s[0]=9*add->ac;
	add->ac_s[1]=9*add->ac;
	printf("\nEnter the AC fare per Seat : ");
	scanf("%f",&add->ac_fare);
	printf("\nEnter how many coaches in Premium Sleeper : ");
	scanf("%d",&add->pr);
	add->pr_b[0]=18 * add->pr;
	add->pr_b[1]=18*add->pr;
	add->pr_b[2]=18*add->pr;
	add->pr_s[0]=9*add->pr;
	add->pr_s[1]=9*add->pr;
	printf("\nEnter the Premium fare per Seat : ");
	scanf("%f",&add->pr_fare);
	printf("\nEnter how many coaches in Non-AC : ");
	scanf("%d",&add->na);
	add->na_avail=120*add->na;
	printf("\nEnter the Non - AC fare per Seat : ");
	scanf("%f",&add->na_fare);
	add->tatkal_avail=25;
	printf("\nEnter the Tatkal fare per Seat : ");
	scanf("%f",&add->tatkal_fare);
	add->next=NULL;
	if (head ==NULL){
		head=add;
	}
	else{
		struct train *temp;
		temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next=add;
	}
	g=fopen("train_det.txt","a+");
	h=fopen("seat_avail.txt","a+");
	if(g==NULL || h==NULL){
		printf("\n\aFile Missing");
		exit(0);
	}
	fprintf(g,"%-8d %-8d %-25s %-25s %-8s %-8s %-25s %f \n",add->rno,add->train_no,add->train_name,add->dept,add->dept_time,add->dest_time,add->arrival,add->distance);
	fprintf(h,"%-8d %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8f %-8f %-8d \n",add->rno,add->ac,add->ac_b[0],add->ac_b[1],add->ac_b[2],add->ac_s[0],add->ac_s[1],add->ac_fare,add->pr,add->pr_b[0],add->pr_b[1],add->pr_b[2],add->pr_s[0],add->pr_s[1],add->pr_fare,add->na,add->na_avail,add->na_fare,add->tatkal_fare,add->tatkal_avail);
	fclose(h);
	fclose(g);
	for(i=0;i<6;i++){
		struct train *ne = (struct train *) malloc(sizeof(struct train));
		ne->rno=sno;
		ne->train_no=add->train_no;
		strcpy(ne->train_name,add->train_name);
		strcpy(ne->dept,add->dept);
		strcpy(ne->dept_time,add->dept_time);
		strcpy(ne->dest_time,add->dest_time);
		strcpy(ne->arrival,add->arrival);
		ne->distance=add->distance;
		ne->ac=add->ac;
		ne->ac_fare=add->ac_fare;
		ne->pr=add->pr;
		ne->pr_fare=add->pr_fare;
		for(j=0;j<3;j++){
			ne->ac_b[j]=add->ac_b[j];
			ne->pr_b[j]=add->pr_b[j];
		}
		for(j=0;j<2;j++){
			ne->ac_s[j]=add->ac_s[j];
			ne->pr_s[j]=add->pr_s[j];
		}
		ne->na=add->na;
		ne->na_avail=add->na_avail;
		ne->na_fare=add->na_fare;
		ne->tatkal_avail=add->tatkal_avail;
		ne->tatkal_fare=add->tatkal_fare;
		ne->next=NULL;
		if (d[i] ==NULL){
			d[i]=ne;
		}
		else{
			struct train *temp;
			temp = d[i];
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next=ne;
		}
		FILE *a;
		switch(i){
			\
			case 0:{
				a=fopen("day_1.txt","a+");
				break;
			}
			case 1:{
				a=fopen("day_2.txt","a+");
				break;
			}
			case 2:{
				a=fopen("day_3.txt","a+");
				break;
			}
			case 3:{
				a=fopen("day_4.txt","a+");
				break;
			}
			case 4:{
				a=fopen("day_5.txt","a+");
				break;
			}
			case 5:{
				a=fopen("day_6.txt","a+");
				break;
			}
		}
		fprintf(a,"%-8d %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8d %-8d %-8d %-8d %-8f %-8d %-8d %-8f %-8f %-8d \n",add->rno,add->ac,add->ac_b[0],add->ac_b[1],add->ac_b[2],add->ac_s[0],add->ac_s[1],add->ac_fare,add->pr,add->pr_b[0],add->pr_b[1],add->pr_b[2],add->pr_s[0],add->pr_s[1],add->pr_fare,add->na,add->na_avail,add->na_fare,add->tatkal_fare,add->tatkal_avail);
		fclose(a);
	}
	tot_train+=1;
	sno++;
	train_writ();
	printf("\n\nTrain Details Added...\n\n");
}
void read_data(){
	FILE *fp,*g,*h;
	fp=fopen("total.txt","r");
	fscanf(fp,"%d %d %d",&tot_train,&sno,&ticket_no);
	fclose(fp);
	short i;
	g=fopen("train_det.txt","r");
	h=fopen("seat_avail.txt","r");
	for(i=0;i<tot_train;i++){
		struct train *add = (struct train *) malloc(sizeof(struct train));
		fscanf(g,"%d %d %s %s %s %s %s %f \n",&add->rno,&add->train_no,&add->train_name,&add->dept,&add->dept_time,&add->dest_time,&add->arrival,&add->distance);
		fscanf(h,"%d %d %d %d %d %d %d %f %d %d %d %d %d %d %f %d %d %f %f %d \n",&add->rno,&add->ac,&add->ac_b[0],&add->ac_b[1],&add->ac_b[2],&add->ac_s[0],&add->ac_s[1],&add->ac_fare,&add->pr,&add->pr_b[0],&add->pr_b[1],&add->pr_b[2],&add->pr_s[0],&add->pr_s[1],&add->pr_fare,&add->na,&add->na_avail,&add->na_fare,&add->tatkal_fare,&add->tatkal_avail);
		add->next=NULL;
		if (head ==NULL){
			head=add;
		}
		else{
			struct train *temp;
			temp = head;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next=add;
		}
 	}
 	fclose(g);
 	fclose(h);
    for (i=0;i<6;i++){
    	FILE *a,*u,*f;
 	    short j;
 	    switch(i){
			case 0:{
				a=fopen("day_1.txt","r");
				break;
			}
			case 1:{
				a=fopen("day_2.txt","r");
				break;
			}
			case 2:{
				a=fopen("day_3.txt","r");
				break;
			}
			case 3:{
				a=fopen("day_4.txt","r");
				break;
			}
			case 4:{
				a=fopen("day_5.txt","r");
				break;
			}
			case 5:{
				a=fopen("day_6.txt","r");
				break;
			}
		}
		u=fopen("train_det.txt","r");
 		for(j=0;j<tot_train;j++){
 			struct train *ne = (struct train *) malloc(sizeof(struct train));
			fscanf(u,"%d %d %s %s %s %s %s %f \n",&ne->rno,&ne->train_no,&ne->train_name,&ne->dept,&ne->dept_time,&ne->dest_time,&ne->arrival,&ne->distance);
			fscanf(a,"%d %d %d %d %d %d %d %f %d %d %d %d %d %d %f %d %d %f %f %d \n",&ne->rno,&ne->ac,&ne->ac_b[0],&ne->ac_b[1],&ne->ac_b[2],&ne->ac_s[0],&ne->ac_s[1],&ne->ac_fare,&ne->pr,&ne->pr_b[0],&ne->pr_b[1],&ne->pr_b[2],&ne->pr_s[0],&ne->pr_s[1],&ne->pr_fare,&ne->na,&ne->na_avail,&ne->na_fare,&ne->tatkal_fare,&ne->tatkal_avail);
			ne->next=NULL;
			if (d[i] == NULL){
				d[i]=ne;
			}
			else{
				struct train *temp;
				temp = d[i];
				while(temp->next!=NULL)
					temp = temp->next;
				temp->next=ne;
			}
		}
		fclose(a);
		fclose(u);
		switch(i){
			case 0:{
				f=fopen("count_day1.txt","r");
				break;
			}
			case 1:{
				f=fopen("count_day2.txt","r");
				break;
			}
			case 2:{
				f=fopen("count_day3.txt","r");
				break;
			}
			case 3:{
				f=fopen("count_day4.txt","r");
				break;
			}
			case 4:{
				f=fopen("count_day5.txt","r");
				break;
			}
			case 5:{
				f=fopen("count_day6.txt","r");
				break;
			}
		}
		fscanf(f,"%d %d %d %d %d %d %d %d %f %f %f %f %lu %d",&z[i].ac,&z[i].pr,&z[i].na,&z[i].tatkal,&z[i].senior_citizen,&z[i].pregnant_women,&z[i].women,&z[i].total_ticket,&z[i].ac_fare,&z[i].pr_fare,&z[i].na_fare,&z[i].tatkal_fare,&z[i].total_fare,&z[i].waiting);
		fclose(f);
	}
}
