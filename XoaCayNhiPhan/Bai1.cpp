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
	
		INCAY(Cay->L);
		printf("%d ", Cay->dlieu);		
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
		if (Cay->L != NULL & Cay->R == NULL)//Cay lech trai
		{
			tg = Cay;
			Cay = Cay->L;
			tg->L = NULL;	
		}
		else
			if (Cay->L == NULL & Cay->R != NULL)//Cay lech phai
			{
				tg = Cay;
				Cay = Cay->R;
				tg->R = NULL;	
			}
			else // cay can b�ng
			{				
				tg = Cay;
				CayR = Cay->R;
				Cay = Cay->L ;
				Cay = BSUNG(Cay, CayR);
			}		
	return Cay;	 
}
NUT *TRUOC(NUT *Cay, NUT *nut)
{
	NUT *tr;
	tr = Cay;
	while (tr->L!=nut && tr->R!= nut)
		if (nut->dlieu < tr->dlieu)
			tr = tr->L;
		else
			tr = tr->R;
	return tr;			
}
NUT *XOA_LA(NUT *Cay, NUT *nut)
{
	NUT *tr;
	tr = TRUOC(Cay, nut);
	if (tr->R==nut)
		tr->R=NULL;
	else
		tr->L =NULL;
	return Cay;				
}
NUT *XOA_TG_T(NUT *Cay, NUT *nut)
{
	NUT *tr;
	tr = TRUOC(Cay, nut);
	if (tr->R == nut)
	{
		tr->R = nut->L;
		nut->L = NULL;
	}
	else
	{
		tr->L = nut->L;
		nut->L = NULL;
	}
	return Cay;			
}
NUT *XOA_TG_P(NUT *Cay, NUT *nut)
{
	NUT *tr;
	tr = TRUOC(Cay, nut);
	if (tr->L ==nut)
	{
		tr->L = nut->R;
		nut->R = NULL;
	}
	else
	{
		tr->R = nut->R;
		nut->R = NULL;	
	}
	return Cay;
}
NUT *XOA_TG(NUT *Cay, NUT *nut)
{
	NUT *tr, *CayR;
	tr = TRUOC(Cay, nut);
	if (tr->L ==nut)
	{
		tr->L = nut->L;
		nut->L = NULL;
		CayR= nut->R;
		nut->R = NULL;
		Cay = BSUNG(Cay, CayR);			
	}
	else
	{
		tr->R = nut->L;
		nut->L =NULL;
		CayR= nut->R;
		nut->R = NULL;
		Cay = BSUNG(Cay, CayR);			
	}
	return Cay;
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
			if (tk->R==NULL && tk->L == NULL)
				Cay = XOA_LA(Cay, tk);
			else
				if (tk->L!=NULL & tk->R == NULL)
					Cay = XOA_TG_T(Cay, tk);
				else
					if (tk->L==NULL & tk->R != NULL)
						Cay = XOA_TG_P(Cay, tk);
					else
						Cay = XOA_TG(Cay, tk);
							
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
