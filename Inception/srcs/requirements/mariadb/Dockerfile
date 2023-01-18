# Pulling minimal image
FROM debian:buster

# # Installing requirements :: mariadb
RUN apt-get -y update && apt-get install -y mariadb-server

# Copying entrypoint from tools
COPY /tools/mariadb-entrypoint.sh /usr/bin

# Running mariadb
ENTRYPOINT ["bash", "/usr/bin/mariadb-entrypoint.sh"]

CMD [ "mysqld_safe" ]