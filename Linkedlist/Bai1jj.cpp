#include <stdio.h>
struct NUT 
		{
			int dlieu;
			NUT *L, *R;
		};
NUT *BSUNG(NUT *Cay, NUT *ptu)		
{
	NUT *tg, *tr;
	if (Cay ==NULL)
		Cay = ptu;
	else
	{
		tg = Cay;
		while (tg!=NULL)
		{
			tr = tg;
			if (ptu->dlieu < tg->dlieu)
				tg = tg->L;
			else
				tg = tg->R;	
		}	
		if (ptu->dlieu < tr->dlieu)
			tr->L = ptu;
		else
			tr->R = ptu;
	}	
	return Cay;
}
void INCAY(NUT *Cay)
{
	if (Cay!=NULL)
	{
		printf("%d ", Cay->dlieu);
		INCAY(Cay->L);
		INCAY(Cay->R);
	}
}

NUT *TKIEM_2(NUT *Cay, int x)
{
	NUT *tg;
	tg = Cay;
	while (tg!=NULL && tg->dlieu != x)
		if (x < tg->dlieu)
			tg = tg->L;
		else
			tg = tg->R;	
	if (tg!=NULL)
		return tg;
	else
		return NULL;			
}
NUT *XOAGOC(NUT *Cay)
{
	NUT *tg, *CayL, *CayR;
	
	if (Cay->L == NULL & Cay->R == NULL)
		Cay = NULL;
	else
		if (Cay->L != NULL & Cay->R == NULL)
		{
			tg = Cay;
			Cay = Cay->L;
			tg->L = NULL;	
		}
		else
			if (Cay->L == NULL & Cay->R != NULL)
			{
				tg = Cay;
				Cay = Cay->R;
				tg->R = NULL;	
			}
			else
			{
				CayL = Cay->L;
				CayR = Cay->R;
				Cay->L = NULL;
				Cay->R= NULL;
				tg = CayR;
				while (tg->L!=NULL)	
					tg = tg->L;
				tg->L = CayL;
				Cay = CayR;	
			}		
	return Cay;	 
}
NUT * XOALA(NUT *Cay, NUT *TK){
	NUT * tmp , * R, * L;
	tmp = Cay ;
	while(tmp->R!=tmp&&tmp->L!=tmp){
		
	}
}
NUT *XOA(NUT *Cay, int x)
{
	NUT *tk;
	while (TKIEM_2(Cay, x)!=NULL)
	{
		tk = TKIEM_2(Cay, x);
		if (tk ==Cay)
			Cay = XOAGOC(Cay);
		else
			Cay = XOALA(Cay, tk);
	}
	return Cay;
}
main()
{
	NUT *Tree, *p;
	int i, n , so;
	printf("Nhap bao nhieu so: ");
	scanf("%d", &n);
	Tree=NULL;
	for (i=1;i<=n; i++)
	{
		p= new NUT;
		printf("Nhap so thu %d: ", i);
		scanf("%d", &p->dlieu);
		p->L=NULL;
		p->R=NULL;
		Tree = BSUNG(Tree, p);
	}
	INCAY(Tree);
	printf("\nNhap so can xoa: ");
	scanf("%d", &so);
	Tree = XOA(Tree, so);
	INCAY(Tree);
}
