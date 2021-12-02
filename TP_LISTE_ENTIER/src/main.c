int main() {
	int v;
	struct lst_t * L = new_lst();
	scanf("%d",&v);
	while( v > 0 ) {
		cons(L,v);
		scanf("%d",&v);
	}
	print_lst(L);
	del_lst(&L);
	return EXIT_SUCCESS;
}