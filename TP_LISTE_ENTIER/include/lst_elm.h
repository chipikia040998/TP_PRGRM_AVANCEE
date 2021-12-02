/** @brief Le type abstrait d'un _élément_ de liste:
* @param x  un entier,
* @param suc un pointeur sur son successeur (ou NULL s'il n'y en a pas)
*/
struct lst_elm_t 
{
	int x;
	struct lst_elm_t * suc;
};

/**************************************/
/* DÉCLARATION DES FONCTIONS ASSOCIÉES*/
/**************************************/

/** @brief Créer un élément de liste et y ranger la valeur entière value 
* @param value valeur a ranger dans le nouvel élément de liste
*/
struct lst_elm_t * new_lst_elm(int value);

/**************************************************************/

/** @brief Supprimer un élément de liste et mettre son pointeur à NULL
* @param ptrE élément a supprimer et poiteur a NULL
*/
void del_lst_elm(struct lst_elm_t ** ptrE);

/**************************************************************/

/** @brief Renvoyer la valeur entière de l'élément 
* @param E Element dont on veux la valeur
*/
int getX ( struct lst_elm_t * E );

/**************************************************************/

/** @brief Renvoyer le pointeur sur le successeur de l'élément 
* @param E Element dont on veux le successeur
*/
struct lst_elm_t * getSuc ( struct lst_elm_t * E );

/**************************************************************/

/** @brief Modifier la valeur entière de l'élément 
* @param E élément a modifier
* @param v nouvelle valeur
*/
void setX (struct lst_elm_t * E, int v );

/**************************************************************/

/** @brief Modifier le pointeur sur le successeur de l'élément 
* @param E élément de départ 
* @param S successeur dont on change le pointeur
*/
void setSuc ( struct lst_elm_t * E, struct lst_elm_t * S );