#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class HBS
{
public:
	double heartbeat;
	HBS *next ;
public:
	HBS()
	{
		double heartbeat=0;
		HBS *next =NULL;	
	}
	HBS(double s)
	{
		heartbeat=s;
		HBS *next = NULL;
	}
};
class HBSS
{
public:
	HBS *head;
	HBS *tail;
	int DATE_LONG ;
	HBSS()
	{
		HBS*p;
		p = new HBS;
		p->heartbeat = 0;
		head = p;
		tail = head;
		DATE_LONG = 1;
	};
	HBSS(double s)
	{
		HBS*p;
		p = new HBS;
		p->heartbeat = s;
		head =p;
		tail = head;
		DATE_LONG = 1;
	}
	HBS*ADD(double s)
	{
		HBS*p;
		p = new HBS;
		p->heartbeat = s;
		tail->next = p;
		tail = p;
		return tail;
		DATE_LONG++;
	}
	/*void HBS_SAVE(string a)
	{
		HBS*p=0;
		ofstream ofile;
		ofile.open("D:\\"+a+".txt");
		p = head;
		for (; p != 0;)
		{
			ofile << p->heartbeat << endl;
			p = p->next;
		}
		ofile.close();
	}*/
};
class period
{
public:
	period*next;
public:
	HBS*headofP;
	HBS*tailofP;
	HBS*headofQ;
	HBS*tailofQ;
	HBS*headofR;
	HBS*tailofR;
	HBS*headofS;
	HBS*tailofS;
	HBS*headofT;
	HBS*tailofT;
public:
	double maxofP;
	double maxofQ;
	double maxofR;
	double maxofS;
	double maxofT;
public:
	double T_P;
	double T_Q;
	double T_R;
	double T_S;
	double T_T;
public:
	double PQ;
	double QRS;
	bool normal;
public:
	period()
	{
		headofP = NULL;
		tailofP = NULL;
		headofQ = NULL;
		tailofQ = NULL;
		headofR = NULL;
		tailofR = NULL;
		headofS = NULL;
		tailofS = NULL;
		headofT = NULL;
		tailofT = NULL;
		maxofP=0;
		maxofQ=0;
		maxofR=0;
		maxofS=0;
		maxofT=0;
		T_P=0;
		T_Q=0;
		T_R=0;
		T_S=0;
		T_T=0;	
		PQ=0;
		QRS=0;
		normal=true;
		next = NULL;
	}
	~period(){}
	HBS*C_PERIOD(HBS*pH, HBSS*phss)
	{
		int i;
		i = 0;
		double max;
		for (; i < 5 && pH !=phss->tail;)
		{
			if (i == 0 &&pH !=phss->tail)
			{
				max = 0;
				for (;pH !=phss->tail&&pH->heartbeat< 0.1;)
				{
					pH = pH->next;
				}
				if (pH !=phss->tail&&pH->heartbeat >= 0.1&&pH != NULL)
				{
					headofP = pH;
				}
				for (;pH !=phss->tail&& pH->heartbeat >= 0.1&&pH != NULL;)
				{
					T_P++;
					if (max < pH->heartbeat)
					{
						max = pH->heartbeat;
					}
					pH = pH->next;
				}
				T_P = T_P*0.0027777;
				maxofP = max;
				tailofP = pH;
				i = 1;
			}
			else if (i == 1 &&pH !=phss->tail)
			{
				max = 0;
				for (; pH !=phss->tail&&pH->heartbeat > 0 &&pH !=phss->tail;)
				{
					pH = pH->next;
				}
				if (pH !=phss->tail&&pH->heartbeat <= 0 &&pH !=phss->tail)
				{
					headofQ = pH;
				}
				for (; pH !=phss->tail&&pH->heartbeat <= 0 &&pH !=phss->tail;)
				{
					T_Q++;
					if (max < pH->heartbeat&&pH != NULL)
					{
						max = pH->heartbeat;
					}
					pH = pH->next;
				}
				T_Q = T_Q*0.0027777;
				maxofQ = max;
				tailofQ = pH;
				i = 2;
			}
			else if (i == 2 &&pH !=phss->tail)
			{
				max = 0;
				for (;pH !=phss->tail&& pH->heartbeat < 0.105&&pH != NULL;)
				{
					pH = pH->next;
				}
				if (pH !=phss->tail&&pH->heartbeat >= 0.105&&pH != NULL)
				{
					headofR = pH;
				}
				for (;pH !=phss->tail&& pH->heartbeat >= 0.105&&pH != NULL;)
				{
					T_R++;
					if (max < pH->heartbeat&&pH != NULL)
					{
						max = pH->heartbeat;
					}
					pH = pH->next;
				}
				T_R = T_R*0.0027777;
				maxofR = max;
				tailofR = pH;
				i = 3;
			}
			else if (i == 3 &&pH !=phss->tail)
			{
				max = 0;
				for (;pH !=phss->tail&& pH->heartbeat > 0 &&pH !=phss->tail;)
				{
					pH = pH->next;
				}
				if (pH !=phss->tail&&pH->heartbeat <= 0 &&pH !=phss->tail)
				{
					headofS = pH;
				}
				for (;pH !=phss->tail&& pH->heartbeat <= 0 &&pH !=phss->tail;)
				{
					T_S++;
					if (max < pH->heartbeat&&pH != NULL)
					{
						max = pH->heartbeat;
					}
					pH = pH->next;
				}
				T_S = T_S*0.0027777;
				maxofS = max;
				tailofS = pH;
				i = 4;
			}
			else if (i == 4 &&pH !=phss->tail)
			{
				max = 0;
				for (;pH !=phss->tail&& pH->heartbeat < 0.11&&pH != NULL;)
				{
					pH = pH->next;
				}		
				if (pH !=phss->tail&&pH->heartbeat >= 0.11&&pH != NULL)
				{
					headofT = pH;
				}
				for (;pH !=phss->tail&& pH->heartbeat >= 0.11&&pH != NULL;)
				{
					T_T++;
					if (max < pH->heartbeat&&pH != NULL)
					{
						max = pH->heartbeat;
					}
					pH = pH->next;
				}
				T_T = T_T*0.0027777;
				maxofT = max;
				tailofT = pH;
				i = 5;
			}
		}
		HBS*pH1 = headofP;
		for (; (pH1 != headofQ) && (pH != 0)&&(pH1!=phss->tail)&&(pH!=phss->tail);)
		{
			PQ++;
			pH1 = pH1->next;
		}
		PQ = PQ*0.0027777;
		pH1 = headofQ;
		for (; (pH1 != headofS)&&(pH != 0)&&(pH1!=phss->tail)&&(pH!=phss->tail);)
		{
			QRS++;
			pH1 = pH1->next;
		}
		QRS = QRS*0.0027777;
		return pH;
	}

};
class period_list
{
public:
	period*head;
	period*tail;
	period_list()
	{
		period*fi;
		fi = new period;
		head = fi;
		tail = fi;
	}
public:
	period*ADD(period*s)
	{
		tail->next = s;
		tail = s;
		if (s->PQ <0.400|| s->PQ >= 0.430 || s->PQ < 0.300 || s->QRS<0.050 || s->maxofT <= 0)
		{
			s->normal = false;
		}
		return tail;
	}
};