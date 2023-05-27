#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <time.h>
#include <math.h>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct data{
  int ID ;
  int CPU_Burst ;
  int Arrival_Time ;
  int Priority ;
  
  int finish ;
  int already ;
  
  int turnaround ;
  int waiting ;
};

bool isexsit( string namestr, vector<data> &nonlist, int &way, int &timeslice ) {
  namestr = namestr + ".txt" ;
  fstream fin ;
  fin.open( namestr.c_str(), ios::in ) ;
  if( !fin ) return false ;
  else{
    string temp ;
    data acct ;
    fin >>  way ;
    fin >> timeslice;
    getline( fin, temp ) ;
    getline( fin, temp ) ;
    while ( fin >> acct.ID >> acct.CPU_Burst >> acct.Arrival_Time >> acct.Priority ) {
      nonlist.push_back( acct ) ;	
    }
    return true ;
  }


  fin.close() ;
  return false ;
}
char inttoch( int id ) {
  char temp ;
  if ( id == 0 ) return '0' ;
  else if ( id == 1 ) return '1' ;
  else if ( id == 2 ) return '2' ;
  else if ( id == 3 ) return '3' ;
  else if ( id == 4 ) return '4' ;
  else if ( id == 5 ) return '5' ;
  else if ( id == 6 ) return '6' ;
  else if ( id == 7 ) return '7' ;
  else if ( id == 8 ) return '8' ;
  else if ( id == 9 ) return '9' ;
  else {
  	id = id + 55 ;
  	char ch = id ;
  	return ch ;
  } 
}

void printsingle( string inputname, vector<data> time_list, vector<char> cpu_queue, string way ) {
  string outputnamestr = "out_" + inputname + "_method" + way + ".txt" ;
  string which ;
  if( way == "1" ) which = "FCFS" ;
  else if( way == "2" ) which = "  RR" ;
  else if( way == "3" ) which = " SJF" ;
  else if( way == "4" ) which = "SRTF" ;
  else if( way == "5" ) which = "HRRN" ;
  else if( way == "6" ) which = "PPRR" ;
  ofstream fout( outputnamestr.c_str() ) ;
  fout << which << "\n" << "==        " + which + "==\n";
  cout << which << "\n" << "==        " + which + "==\n";
  for( int i = 0 ; i < cpu_queue.size() ; i++ ) fout << cpu_queue[i] ;
  for( int i = 0 ; i < cpu_queue.size() ; i++ ) cout << cpu_queue[i] ;
  fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;
  fout << "Waiting Time\n" << "ID           " + which + "\n";
  cout << "Waiting Time\n" << "ID           " + which + "\n";
  fout << "===========================================================\n" ;
  cout << "===========================================================\n" ;
  for( int i = 0 ; i < time_list.size() ; i++ ) {
  	fout << time_list[i].ID  << "\t" << time_list[i].waiting << "\n";
  	cout << time_list[i].ID  << "\t" << time_list[i].waiting << "\n";
	}
	fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;
  fout << "Turnaround Time\n" << "ID           " + which + "\n";
  cout << "Turnaround Time\n" << "ID           " + which + "\n";
  fout << "===========================================================\n" ;
  cout << "===========================================================\n" ;
  for( int i = 0 ; i < time_list.size() ; i++ ) {
  	fout << time_list[i].ID  << "\t" << time_list[i].turnaround << "\n";
  	cout << time_list[i].ID  << "\t" << time_list[i].turnaround << "\n";
  }
  fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;
  fout.close() ;
}
void printall( string filename, vector<char> FCFS_cpu, vector<char> RR_cpu, vector<char> SJF_cpu, vector<char> SRTF_cpu, vector<char> HRRN_cpu, vector<char> PPRR_cpu, vector<data> FCFS_list, vector<data> RR_list, vector<data> SJF_list, vector<data> SRTF_list, vector<data> HRRN_list, vector<data> PPRR_list ) {
  string outputnamestr = "out_" + filename + ".txt" ;
  ofstream fout( outputnamestr.c_str() ) ;
  fout << "All\n" ;
  cout << "All\n" ;
  fout << "==        FCFS==\n";
  cout << "==        FCFS==\n";
  for( int i = 0 ; i < FCFS_cpu.size() ; i++ ) fout << FCFS_cpu[i] ;
  for( int i = 0 ; i < FCFS_cpu.size() ; i++ ) cout << FCFS_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;
  fout << "==          RR==\n";
  cout << "==          RR==\n";
  for( int i = 0 ; i < RR_cpu.size() ; i++ ) fout << RR_cpu[i] ;
  for( int i = 0 ; i < RR_cpu.size() ; i++ ) cout << RR_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;
  fout << "==         SJF==\n";
  cout << "==         SJF==\n";
  for( int i = 0 ; i < SJF_cpu.size() ; i++ ) fout << SJF_cpu[i] ;
  for( int i = 0 ; i < SJF_cpu.size() ; i++ ) cout << SJF_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;
  fout << "==        SRTF==\n";
  cout << "==        SRTF==\n";
  for( int i = 0 ; i < SRTF_cpu.size() ; i++ ) fout << SRTF_cpu[i] ;
  for( int i = 0 ; i < SRTF_cpu.size() ; i++ ) cout << SRTF_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;
  fout << "==        HRRN==\n";
  cout << "==        HRRN==\n";
  for( int i = 0 ; i < HRRN_cpu.size() ; i++ ) fout << HRRN_cpu[i] ;
  for( int i = 0 ; i < HRRN_cpu.size() ; i++ ) cout << HRRN_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;   
  fout << "==        PPRR==\n";
  cout << "==        PPRR==\n";
  for( int i = 0 ; i < PPRR_cpu.size() ; i++ ) fout << PPRR_cpu[i] ;
  for( int i = 0 ; i < PPRR_cpu.size() ; i++ ) cout << PPRR_cpu[i] ;
  fout << "\n" ;
  cout << "\n" ;
  fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;
  fout << "Waiting Time\n" << "ID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n";
  cout << "Waiting Time\n" << "ID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n";
  fout << "===========================================================\n" ;
  cout << "===========================================================\n" ;  
  for( int i = 0 ; i < FCFS_list.size() ; i++ ) {
  	fout << FCFS_list[i].ID  << "\t" << FCFS_list[i].waiting <<"\t" << RR_list[i].waiting << "\t" << SJF_list[i].waiting << "\t" << SRTF_list[i].waiting << "\t" << HRRN_list[i].waiting << "\t" << PPRR_list[i].waiting << "\n";
  	cout << FCFS_list[i].ID  << "\t" << FCFS_list[i].waiting <<"\t" << RR_list[i].waiting << "\t" << SJF_list[i].waiting << "\t" << SRTF_list[i].waiting << "\t" << HRRN_list[i].waiting << "\t" << PPRR_list[i].waiting << "\n";
  }  
  fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;	
  fout << "Turnaround Time\n" << "ID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n";
  cout << "Turnaround Time\n" << "ID\tFCFS\tRR\tSJF\tSRTF\tHRRN\tPPRR\n";
  fout << "===========================================================\n" ;
  cout << "===========================================================\n" ;
  for( int i = 0 ; i < FCFS_list.size() ; i++ ) {
  	fout << FCFS_list[i].ID  << "\t" << FCFS_list[i].turnaround <<"\t" << RR_list[i].turnaround << "\t" << SJF_list[i].turnaround << "\t" << SRTF_list[i].turnaround << "\t" << HRRN_list[i].turnaround << "\t" << PPRR_list[i].turnaround << "\n";
  	cout << FCFS_list[i].ID  << "\t" << FCFS_list[i].turnaround <<"\t" << RR_list[i].turnaround << "\t" << SJF_list[i].turnaround << "\t" << SRTF_list[i].turnaround << "\t" << HRRN_list[i].turnaround << "\t" << PPRR_list[i].turnaround << "\n";
  }
  fout << "===========================================================\n" << "\n" ;
  cout << "===========================================================\n" << "\n" ;  
  fout.close() ;
}
void checkready( vector<data> nonlist, vector<int> &ready_queue,int now_time ) {
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
  	if( now_time == nonlist[i].Arrival_Time ) ready_queue.push_back( nonlist[i].ID ) ;
  }
}
void updateby_CPU_Burst( vector<data> nonlist, vector<int> &ready_queue ) {
  for( int x = ready_queue.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      data process1, process2 ;
      for( int i = 0 ; i < nonlist.size() ; i++ ) {
      	if( ready_queue[y] == nonlist[i].ID ) process1 = nonlist[i] ;
      	if( ready_queue[y+1] == nonlist[i].ID ) process2 = nonlist[i] ;
	  }
      
      
      if( process1.CPU_Burst > process2.CPU_Burst ){
        int temp = ready_queue[y] ;
        ready_queue[y] = ready_queue[y+1] ;
        ready_queue[y+1] = temp ;
      }
      
    } // for
  } // for
}
void updateby_already( vector<data> nonlist, vector<int> &ready_queue ) {
  for( int x = ready_queue.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      data process1, process2 ;
      for( int i = 0 ; i < nonlist.size() ; i++ ) {
      	if( ready_queue[y] == nonlist[i].ID ) process1 = nonlist[i] ;
      	if( ready_queue[y+1] == nonlist[i].ID ) process2 = nonlist[i] ;
	  }
      
      
      if( process1.CPU_Burst - process1.already > process2.CPU_Burst - process2.already ){
        int temp = ready_queue[y] ;
        ready_queue[y] = ready_queue[y+1] ;
        ready_queue[y+1] = temp ;
      }
      
    } // for
  } // for
}
int find_minundone( vector<data> nonlist, vector<int> ready_queue ) {
  int x = 99999 ;
	
  for( int i = 1 ; i < ready_queue.size() ; i++ ) {
  	for( int j = 0 ; j < nonlist.size() ; j++ ) {
  	  if( ready_queue[i] == nonlist[j].ID ) {
  	    if( x > nonlist[j].CPU_Burst - nonlist[j].already ) x = nonlist[j].CPU_Burst - nonlist[j].already ;
  	    break ;
	  }
	}
  } // for
  
  return x ;
}
int find_minPriority( vector<data> nonlist, vector<int> ready_queue ) {
  int x = 99999 ;
	
  for( int i = 1 ; i < ready_queue.size() ; i++ ) {
  	for( int j = 0 ; j < nonlist.size() ; j++ ) {
  	  if( ready_queue[i] == nonlist[j].ID ) {
  	    if( x > nonlist[j].Priority ) x = nonlist[j].Priority ;
  	    break ;
	  }
	}
  } // for
  
  return x ;
}
void updateby_RR( vector<data> nonlist, vector<int> &ready_queue, int now_time ) {
  for( int x = ready_queue.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      data process1, process2 ;
      float process1_RR = 0, process2_RR = 0 ;
      for( int i = 0 ; i < nonlist.size() ; i++ ) {
      	if( ready_queue[y] == nonlist[i].ID ) process1 = nonlist[i] ;
      	if( ready_queue[y+1] == nonlist[i].ID ) process2 = nonlist[i] ;
	  }
	  
      process1_RR = float( ( now_time + process1.CPU_Burst - process1.Arrival_Time ) ) / float( process1.CPU_Burst ) ;
	  process2_RR = float( ( now_time + process2.CPU_Burst - process2.Arrival_Time ) ) / float( process2.CPU_Burst ) ;
      
      if( process1_RR < process2_RR ){
        int temp = ready_queue[y] ;
        ready_queue[y] = ready_queue[y+1] ;
        ready_queue[y+1] = temp ;
      }
      
    } // for
  } // for
}
void updateby_Priority( vector<data> nonlist, vector<int> &ready_queue ) {
  for( int x = ready_queue.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      data process1, process2 ;
      for( int i = 0 ; i < nonlist.size() ; i++ ) {
      	if( ready_queue[y] == nonlist[i].ID ) process1 = nonlist[i] ;
      	if( ready_queue[y+1] == nonlist[i].ID ) process2 = nonlist[i] ;
	  }
      
      
      if( process1.Priority > process2.Priority ){
        int temp = ready_queue[y] ;
        ready_queue[y] = ready_queue[y+1] ;
        ready_queue[y+1] = temp ;
      }
      
    } // for
  } // for
}
void updateby_Arrival_Time( vector<data> &nonlist ) {
  for( int x = nonlist.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      if( nonlist[y].Arrival_Time > nonlist[y+1].Arrival_Time ){
        data temp = nonlist[y] ;
        nonlist[y] = nonlist[y+1] ;
        nonlist[y+1] = temp ;
      }
      else if( nonlist[y].Arrival_Time == nonlist[y+1].Arrival_Time ){
        if( nonlist[y].ID > nonlist[y+1].ID ) {
          data temp = nonlist[y] ;
          nonlist[y] = nonlist[y+1] ;
          nonlist[y+1] = temp ;
        } // if
      } // else if
    } // for
  } // for
}
void listby_ID( vector<data> &nonlist ) {
  for( int x = nonlist.size() - 1 ; x > 0 ; x-- ) {
    for( int y = 0 ; y <= x - 1 ; y++ ) {
      if( nonlist[y].ID > nonlist[y+1].ID ){
        data temp = nonlist[y] ;
        nonlist[y] = nonlist[y+1] ;
        nonlist[y+1] = temp ;
      }
      
    } // for
  } // for
}
void FCFS( vector<data> &nonlist, vector<char> &cpu_queue ) {
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	}
	else {
	  for ( int i = 0 ; i < nonlist.size() ; i++ ) {
        if( ready_queue[0] == nonlist[i].ID ) {
          for ( int j = 0 ; j < nonlist[i].CPU_Burst ; j++ ) {
            
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
	        now_time++ ;
            checkready( nonlist, ready_queue, now_time ) ;
          }
          
          nonlist[i].finish = now_time ;
          break ;
		}
	  }
	  
      process_num++ ;
      ready_queue.erase(ready_queue.begin());
	}
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;

  }
  
  listby_ID( nonlist ) ;
}
void RR( vector<data> &nonlist, int timeslice, vector<char> &cpu_queue ) { 
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	}
	else {
	  for ( int i = 0 ; i < nonlist.size() ; i++ ) {
        if( ready_queue[0] == nonlist[i].ID ) {
          for ( int j = 0 ; j < timeslice && nonlist[i].CPU_Burst - nonlist[i].already > 0 ; j++ ) {
            // cout << inttoch( nonlist[i].ID) ;
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
            nonlist[i].already++ ;
	        now_time++ ;
            checkready( nonlist, ready_queue, now_time ) ;

          }
          
          if( nonlist[i].CPU_Burst - nonlist[i].already != 0 ) ready_queue.push_back( nonlist[i].ID ) ;
		  else {
            nonlist[i].finish = now_time ;
            process_num++ ;
		  }
		  
		  ready_queue.erase(ready_queue.begin());
          break ;
		}
	  }	       
	}
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;

  }
  
  listby_ID( nonlist ) ;
}
void SJF( vector<data> &nonlist, vector<char> &cpu_queue ) {
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	}
	else {
	  for ( int i = 0 ; i < nonlist.size() ; i++ ) {
	  	updateby_CPU_Burst( nonlist, ready_queue ) ;
        if( ready_queue[0] == nonlist[i].ID ) {
          for ( int j = 0 ; j < nonlist[i].CPU_Burst ; j++ ) {
            
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
	        now_time++ ;
            checkready( nonlist, ready_queue, now_time ) ;
          }
          
          nonlist[i].finish = now_time ;
          break ;
		}
	  }
	  
      process_num++ ;
      ready_queue.erase(ready_queue.begin());
	}
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;

  }
  
  listby_ID( nonlist ) ;
}
void HRRN( vector<data> &nonlist, vector<char> &cpu_queue ) {
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	}
	else {
	  for ( int i = 0 ; i < nonlist.size() ; i++ ) {
	  	updateby_RR( nonlist, ready_queue, now_time ) ;
        if( ready_queue[0] == nonlist[i].ID ) {
          for ( int j = 0 ; j < nonlist[i].CPU_Burst ; j++ ) {
            
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
	        now_time++ ;
            checkready( nonlist, ready_queue, now_time ) ;
          }
          
          nonlist[i].finish = now_time ;
          break ;
		}
	  }
	  
      process_num++ ;
      ready_queue.erase(ready_queue.begin());
	}
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;
  }
  
  listby_ID( nonlist ) ;
}
void SRTF( vector<data> &nonlist, vector<char> &cpu_queue ) {
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	  }
	  else {
	    for ( int i = 0 ; i < nonlist.size() ; i++ ) {
	  	  updateby_already( nonlist, ready_queue ) ;
        if( ready_queue[0] == nonlist[i].ID ) {
        // cout << ready_queue[0] ;
          for ( int j = nonlist[i].already ; j < nonlist[i].CPU_Burst && find_minundone( nonlist, ready_queue ) >= nonlist[i].CPU_Burst - nonlist[i].already ; j++ ) {
            // cout << now_time << " " << nonlist[i].ID << " " << find_minundone( nonlist, ready_queue ) << " " << nonlist[i].CPU_Burst - nonlist[i].already << "\n" ;
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
	          now_time++ ;
	          nonlist[i].already++ ;
            checkready( nonlist, ready_queue, now_time ) ;
          }
          
          if( nonlist[i].CPU_Burst -  nonlist[i].already > 0 ) ready_queue.push_back( nonlist[i].ID ) ;
		      else {
            nonlist[i].finish = now_time ;
            process_num++ ;
		      }
		  
		      ready_queue.erase(ready_queue.begin());
          break ;
	      }
	    }
	  
    }
  	
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;
  }
  
  listby_ID( nonlist ) ;
}
void PPRR( vector<data> &nonlist, int timeslice, vector<char> &cpu_queue ) {
  updateby_Arrival_Time( nonlist ) ; 
  vector<int> ready_queue ;
  int now_time = 0 ;
  int process_num = 0 ;
  checkready( nonlist, ready_queue, now_time ) ;
  while( process_num < nonlist.size() ) {
  	if( ready_queue.size() == 0 ) {
  	  cpu_queue.push_back( '-' ) ;
  	  now_time++ ;
  	  checkready( nonlist, ready_queue, now_time ) ;
	}
	else {
      updateby_Priority( nonlist, ready_queue ) ;
	  for ( int i = 0 ; i < nonlist.size() ; i++ ) {
	  	
        if( ready_queue[0] == nonlist[i].ID ) {
        	
        	
          for ( int j = 0 ; nonlist[i].Priority <= find_minPriority( nonlist, ready_queue ) && nonlist[i].CPU_Burst - nonlist[i].already > 0 ; j++ ) {
          	
            if( nonlist[i].Priority == find_minPriority( nonlist, ready_queue ) && j >= timeslice ) {
              break ;
			}
			
            
            
            cpu_queue.push_back( inttoch( nonlist[i].ID )) ;
            
            nonlist[i].already++ ;
	        now_time++ ;
            checkready( nonlist, ready_queue, now_time ) ;

          }
          
          if( nonlist[i].CPU_Burst - nonlist[i].already != 0 ) ready_queue.push_back( nonlist[i].ID ) ;
		  else {
            nonlist[i].finish = now_time ;
            process_num++ ;
		  }
		  
		  ready_queue.erase(ready_queue.begin());
          break ;
		}
	  }
	  
      
	}
  	
  }
  
  for( int i = 0 ; i < nonlist.size() ; i++ ) {
	nonlist[i].turnaround = nonlist[i].finish - nonlist[i].Arrival_Time ;
	nonlist[i].waiting = nonlist[i].turnaround - nonlist[i].CPU_Burst ;
  }
  
  listby_ID( nonlist ) ;
}

int main(int argc, char** argv) {
    string filename ;
    vector<data>nonlist ;
    int timeslice = 0, way = 0 ;
    
    while(1){
      do {
        cout << "Please enter file name.  no.txt\n" ;
        cin >> filename ;

      } while( !isexsit( filename, nonlist, way, timeslice ) ) ;
      
      
      vector<char>FCFS_cpu, RR_cpu, SJF_cpu, SRTF_cpu, HRRN_cpu, PPRR_cpu ;
      vector<data>FCFS_list, RR_list, SJF_list, SRTF_list, HRRN_list, PPRR_list ;
      
      FCFS_list.assign( nonlist.begin() , nonlist.end() ) ;
      RR_list.assign( nonlist.begin() , nonlist.end() ) ;
      SJF_list.assign( nonlist.begin() , nonlist.end() ) ;
      SRTF_list.assign( nonlist.begin() , nonlist.end() ) ;
      HRRN_list.assign( nonlist.begin() , nonlist.end() ) ;
      PPRR_list.assign( nonlist.begin() , nonlist.end() ) ;
      
      if ( way == 1 ) {
      	FCFS( FCFS_list, FCFS_cpu );
      	printsingle( filename, FCFS_list, FCFS_cpu, "1" ) ; 
			}
      else if ( way == 2 ) {
      	RR( RR_list, timeslice, RR_cpu );
      	printsingle( filename, RR_list, RR_cpu, "2" ) ; 
			}
      else if ( way == 3 ) {
      	SJF( SJF_list, SJF_cpu );
      	printsingle( filename, SJF_list, SJF_cpu, "3" ) ; 
			}
      else if ( way == 4 ) {
      	SRTF( SRTF_list, SRTF_cpu );
      	printsingle( filename, SRTF_list, SRTF_cpu, "4" ) ; 
			}
      else if ( way == 5 ) {
      	HRRN( HRRN_list, HRRN_cpu );
      	printsingle( filename, HRRN_list, HRRN_cpu, "5" ) ; 
			}
      else if ( way == 6 ) {
      	PPRR( PPRR_list, timeslice, PPRR_cpu );
        printsingle( filename, PPRR_list, PPRR_cpu, "6" ) ; 
			}
      else if ( way == 7 ) {
      	FCFS( FCFS_list, FCFS_cpu );
      	RR( RR_list, timeslice, RR_cpu );
      	SJF( SJF_list, SJF_cpu );
      	SRTF( SRTF_list, SRTF_cpu );
      	HRRN( HRRN_list, HRRN_cpu );
      	PPRR( PPRR_list, timeslice, PPRR_cpu );
      	printall( filename, FCFS_cpu, RR_cpu, SJF_cpu, SRTF_cpu, HRRN_cpu, PPRR_cpu, FCFS_list, RR_list, SJF_list, SRTF_list, HRRN_list, PPRR_list ) ; 
	  	
      }
      
      /*
    for( int i = 0 ; i < nonlist.size() ; i++ ) {
	  cout << nonlist[i].Priority << "\n" ;
    }
*/
      nonlist.clear() ;
      timeslice = 0, way = 0 ;
    }
    
	return 0;
}
