u1 = udp('laptop', 'RemotePort', 80, 'LocalPort', 53); %computer
u2 = udp('esp', 'RemotePort', 53, 'LocalPort', 80); %computer

fopen(u1);
fopen(u2);

fprintf(u1, 'Ready for data transfer.');

%On host doetom.dhpc, read data coming in from the remote host via u2:

fscanf(u2);