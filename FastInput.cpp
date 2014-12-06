const int MAXSIZE = 20000000;

char buffer[MAXSIZE];
int curpos = 0;
void CIN(int *x)
{
	*x = 0;
	while(buffer[curpos] == ' ' || buffer[curpos] == '\r' || buffer[curpos] == '\n') curpos++;
	
	while (buffer[curpos]!='\0' && buffer[curpos]!='\n' && buffer[curpos]!='\r' && buffer[curpos]!='\x10' && buffer[curpos]!=' ')
	{
		*x = (*x)*10 + (buffer[curpos]-'0');
		curpos++;
	}
}


int main()
{
	cin.read(buffer, MAXSIZE);
}