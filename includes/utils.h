/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeong <youjeong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:14:38 by youjeong          #+#    #+#             */
/*   Updated: 2023/08/25 13:13:00 by youjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

void	*xmalloc(size_t bytes);
void	*xrealloc(void *ptr, size_t bytes);
char	*ft_xstrdup(const char *s1);
char	*ft_xsubstr(const char *s, unsigned int start, size_t len);
char	*ft_xstrjoin(const char *s1, const char *s2);
char	*ft_xitoa(int n);

#endif
