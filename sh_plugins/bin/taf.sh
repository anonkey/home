# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    taf.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 01:05:06 by tseguier          #+#    #+#              #
#    Updated: 2014/04/15 20:46:21 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if [ "$1" = "-s" ];
then
	dir=`echo ~/sh_plugins/tafdirs/dir_$2`
	echo "$PWD" > ${dir}
	echo "${dir}"
elif [ "$1" = "-l" ];
then
	ls -1 ~/sh_plugins/tafdirs/
elif [ "$1" = "-r" ];
then
	rm ~/sh_plugins/tafdirs/dir_$2
else
	dir=`echo ~/sh_plugins/tafdirs/dir_$1`
	cd "`cat ${dir}`"
fi
