#!/usr/bin/env zsh
 
# Complétion
autoload -U compinit
compinit
 
export PATH=/nfs/zfs-student-4/users/2013/tseguier/sh_plugins/bin/:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin:/nfs/zfs-student-4/users/2013/tseguier/.brew/bin

#Insensible à la casse
zstyle ':completion:*' matcher-list '' 'm:{a-zA-Z}={A-Za-z}'
 
#compinstall
zstyle ':completion:*:descriptions' format '%U%B%d%b%u'
zstyle ':completion:*:warnings' format '%BSorry, no matches for: %d%b'
zstyle ':completion:*:sudo:*' command-path /usr/local/sbin /usr/local/bin \
                             /usr/sbin /usr/bin /sbin /bin /usr/X11R6/bin
# Crée un cache des complétion possibles
# très utile pour les complétion qui demandent beaucoup de temps
# comme la recherche d'un paquet aptitude install moz<tab>
zstyle ':completion:*' use-cache on
zstyle ':completion:*' cache-path ~/.zsh_cache
# des couleurs pour la complétion
# faites un kill -9 <tab><tab> pour voir :)
zmodload zsh/complist
setopt extendedglob
zstyle ':completion:*:*:kill:*:processes' list-colors "=(#b) #([0-9]#)*=36=31"
 
# Correction des commandes
setopt correctall
 
autoload colors; colors
export PS1="%B%{$fg[red]%}[%T]%{$reset_color%}%{$fg[green]%}%B %n:%1~/%{$reset_color%}%B%#~>%b "
RPROMPT="%{$fg[green]%}%B[(%?) %D{%d/%m/%y}]%{$reset_color%}" 
# Les alias marchent comme sous bash
alias nrma="norminette *.[hc]"
alias nrm="norminette"
alias src='source ~/.zshrc'
alias re='make re'
alias gc='git clone'
alias ga='git add'
alias gco='git commit -m'
alias gp='git push'
alias taf='. taf'
alias staf='taf -s'
alias ltaf='taf -l'
alias rtaf='taf -r'
alias l='ls'
alias la='ls -a'
alias lla='ls -la'
alias ll='ls -l'
# marre de se faire corriger par zsh ;)
alias sl='ls'
# Alias df -h
alias df='df -h'


# C'est plus joli quand grep met en couleur l'expression reconnue:
export GREP_COLOR="01;31"
# on ne peut pas utiliser GREP_OPTIONS pour rajouter la couleur car cela 
# casse /usr/bin/grep sur les freebsd
#export GREP_OPTIONS="--color=auto"
alias grep='grep --color=auto'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'

# Les trois lignes suivantes changent le comportement de rm, cp et mv de
# manière à ce que ces programmes demandent confirmation avant d'effacer un
# fichier.
alias rm="nocorrect rm -i"
alias mv="nocorrect mv -i"
alias cp="nocorrect cp -i"
 
# un VRAI éditeur de texte ;)
export EDITOR=/usr/bin/vim
 
#Activer l'historique des commandes:
HISTFILE=~/.history
HISTSIZE=1000
SAVEHIST=1000
export HISTFILE SAVEHIST
