#include<iostream>
#include<crafter.h>
#include<string.h>
using namespace std;
using namespace Crafter;

int main()
{
	string iface="eth0";				//set interface where interface is wired lan
	string my_ip=GetMyIP(iface);      	//get the ip associated with interface
	cout<<"My IP address is :"<<my_ip;

	while(true)
	{
		IP ip_header;   //create an ip header
		ip_header.SetSourceIP(my_ip);						//set source ip
		ip_header.SetDestinationIP("www.gmail.com");		//set destination ip


		TCP tcp_header;    //create a tcp header
		tcp_header.SetSrcPort(11);				//11:port for active user(TCP/UDP)
		tcp_header.SetDstPort(80);				//80:port for http
		tcp_header.SetSeqNumber(RNG32());   //TO SET RANDOM SEQUENCE NUMBER
		 tcp_header.SetFlags(TCP::SYN);		// set flag as synchronize


		UDP udp_header;     //create a udp header
		udp_header.SetSrcPort(1024);
 		udp_header.SetSrcPort(69);

 		// Create a packets
        Packet tcp_packet = ip_header / tcp_header;
        Packet udp_packet = ip_header / udp_header;

        /* Write the packet on the wire */
        tcp_packet.Send();
		udp_packet.Send();

		//dislaying the packets on the console
		cout << endl << "\n## captured packets are:\n" << endl;
        tcp_packet.Print();
		cout<<"\n";
		udp_packet.Print();
 	}
	return 0;
}
