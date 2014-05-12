#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    backup.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/14 16:02:14 by tseguier          #+#    #+#              #
#    Updated: 2014/01/14 17:07:19 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

path=$HOME"/bak/"
now=$(date +"%Y-%m-%d/%H-%M-%S")
bakdir=$(basename $PWD)
bakdir=${path}${bakdir}"/"${now}
if [ ! -d "$bakdir" ]; then
	mkdir -p $bakdir
fi
echo $bakdir
cp -R ./* $bakdir
