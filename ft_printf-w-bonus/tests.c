/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:39:00 by xrodrigu          #+#    #+#             */
/*   Updated: 2022/11/02 01:12:31 by xrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("%x*{S5-~w9qa%i:kF~@w Zs7%XI_Ld5|7%u3Ve\vRv%d %xrrWW %pPc<\n)QLDVH", -93254154, 1054114744, 1392463042, 869711628, -503733586, -742939970, (void *)8298585573070304080);
	printf("\n\n");
	b = printf("%x*{S5-~w9qa%i:kF~@w Zs7%XI_Ld5|7%u3Ve\vRv%d %xrrWW %pPc<\n)QLDVH", -93254154, 1054114744, 1392463042, 869711628, -503733586, -742939970, (void *)8298585573070304080);
	printf("\n\nreturns\nprintf: %i\nft_printf: %i", b, a);

	printf("\n%p\n", 8298585573070304080);
	ft_printf("\n%p\n", (void *)8298585573070304080);

	a = ft_printf("gh-8^%X9{i)wq\fk%u 4z*%x\rt|T&y@zc%c9%u-#^F^-;Q-+%i6%i%X?mb[~%X*U%p", -1356075255, -1675758568, -2096231253, -280207097, 1056554421, -1810922349, -919744804, -937701303, -487893641, (void *)-7615005968928980294);
	b = printf("gh-8^%X9{i)wq\fk%u 4z*%x\rt|T&y@zc%c9%u-#^F^-;Q-+%i6%i%X?mb[~%X*U%p", -1356075255, -1675758568, -2096231253, -280207097, 1056554421, -1810922349, -919744804, -937701303, -487893641, (void *)-7615005968928980294);
	printf("\n\nft: %i, p: %i\n\n", a, b);

	ft_printf("-#^F^-;Q-+%i6%i%X?mb[~%X*U%p\n", -1810922349, -919744804, -937701303, -487893641, (void *)-7615005968928980294);
	printf("\n-#^F^-;Q-+%i6%i%X?mb[~%X*U%p", -1810922349, -919744804, -937701303, -487893641, (void *)-7615005968928980294);

	
	return (0);
}
