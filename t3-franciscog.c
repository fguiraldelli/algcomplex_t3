/************************************************************************
*																		*
*						Trabalho 3 - Complexidade						*
*							Profª. Cândida								*
*																		*
*		Aluno: Francisco A. C. C. B. Guiraldelli	RA: 379840			*
*																		*
************************************************************************/


#include <stdio.h>

#define PISCINA 3


//int calcula_soma(int *vetor_1, int *vetor_2, int i, int t, soma){

//}

void mergeSort(int numbers[], int temp[], int array_size)
{
	m_sort(numbers, temp, 0, array_size - 1);
}


void m_sort(int numbers[], int temp[], int left, int right)
{
	int mid;

	if (right > left)
	{
		mid = (right + left) / 2;
		m_sort(numbers, temp, left, mid);
		m_sort(numbers, temp, mid+1, right);

		merge(numbers, temp, left, mid+1, right);
	}
}

void merge(int numbers[], int temp[], int left, int mid, int right)
{
	int i, left_end, num_elements, tmp_pos;

	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;

	while ((left <= left_end) && (mid <= right))
	{
		if (numbers[left] <= numbers[mid])
		{
			temp[tmp_pos] = numbers[left];
			tmp_pos = tmp_pos + 1;
			left = left +1;
		}
		else
		{
			temp[tmp_pos] = numbers[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}

	while (left <= left_end)
	{
		temp[tmp_pos] = numbers[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
	}
	while (mid <= right)
	{
		temp[tmp_pos] = numbers[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}

	for (i=0; i <= num_elements; i++)
	{
		numbers[right] = temp[right];
		right = right - 1;
	}
}

int main(){

	int quantidade_peixes, soma;
	int i, j, t;
	i = 0;
	//int * parcela;
	int * piscina_1, *piscina_2, *piscina_3;
	int * piscina_1_temp, *piscina_2_temp, *piscina_3_temp;
	int combinacao_soma;
	//int total_peixes;
	//long long int total_combinacoes;
	quantidade_peixes = 1;
	int resposta;

	/*Inicio do laço do programa com as entrada*/
	while (quantidade_peixes || soma){
		resposta = 0;
		scanf("%d %d", &quantidade_peixes, &soma);

		/*Cria dinamicamente os vetores parcela e combinacao_soma*/
		piscina_1 = malloc(quantidade_peixes * sizeof(int));
		piscina_2 = malloc(quantidade_peixes * sizeof(int));
		piscina_3 = malloc(quantidade_peixes * sizeof(int));
		piscina_1_temp = malloc(quantidade_peixes * sizeof(int));
		piscina_2_temp = malloc(quantidade_peixes * sizeof(int));
		piscina_3_temp = malloc(quantidade_peixes * sizeof(int));

		/*Preenche os valores dos peixes de cada piscina*/
		for(i = 0; i < quantidade_peixes; i++)
			scanf("%d", &piscina_1[i]);
		for(i = 0; i < quantidade_peixes; i++)
			scanf("%d", &piscina_2[i]);
		for(i = 0; i < quantidade_peixes; i++)
			scanf("%d", &piscina_3[i]);

		/*Faz a Ordenação dos vetores*/
		mergeSort(piscina_1, piscina_1_temp, quantidade_peixes);
		mergeSort(piscina_2, piscina_2_temp, quantidade_peixes);
		mergeSort(piscina_3, piscina_3_temp, quantidade_peixes);

		/*Faz a combinação da soma dos vetores 1 e 2 com cada elemento do 3*/
		for(i = 0; i < quantidade_peixes; i++){
			t = quantidade_peixes-1;
			j=0;
			while(j <= t){
				combinacao_soma = piscina_1[j] + piscina_2[t]	+ piscina_3[i];
				if(combinacao_soma == soma){
					resposta = 1;
					break;
				}
				else if(combinacao_soma > soma)
					t--;
				else
					j++;
			}
			if (resposta)
				break;
		}
		if(!resposta){
			for(i = 0; i < quantidade_peixes; i++){
				t = quantidade_peixes-1;
				j=0;
				while(j <= t){
					combinacao_soma = piscina_1[j] + piscina_3[t]	+ piscina_2[i];
					if(combinacao_soma == soma){
						resposta = 1;
						break;
					}
					else if(combinacao_soma > soma)
						t--;
					else
						j++;
				}
				if (resposta)
					break;
			}
		}
		if(!resposta){
			for(i = 0; i < quantidade_peixes; i++){
				t = quantidade_peixes-1;
				j=0;
				while(j <= t){
					combinacao_soma = piscina_3[j] + piscina_2[t]	+ piscina_1[i];
					if(combinacao_soma == soma){
						resposta = 1;
						break;
					}
					else if(combinacao_soma > soma)
						t--;
					else
						j++;
				}
				if (resposta)
					break;
			}
		}

		/*Se a resposta for 1 - responde SIM*/
		if(quantidade_peixes || soma){
			if(resposta)
				printf("SIM\n");
			else
				printf("NÃO\n");
		}

		//free(piscina_1);
		//free(piscina_2);
		//free(piscina_3);

	}
	return 0;
}
