# Pulling the minimal image
FROM debian:buster

# Installing requirements :: ngnix
RUN apt-get -yq update && apt-get -yq install nginx
RUN apt-get -yq install vim
RUN apt-get -yq install openssl

# Copying a ngnix configuration file from conf
COPY /conf/wordpress.conf /etc/nginx/conf.d/

# Copying entrypoint from tools
COPY /tools/docker-entrypoint.sh /usr/bin/

# Running ngnix server
ENTRYPOINT ["bash", "/usr/bin/docker-entrypoint.sh"]
