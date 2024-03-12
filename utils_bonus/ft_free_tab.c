#include "../pipex_bonus.h"

void	ft_free_tab(void **tab)
{
	void	**tmp;

	if (!tab)
		return ;
	tmp = tab;
	while (*tmp)
		free(*(tmp++));
	free(tab);
}
