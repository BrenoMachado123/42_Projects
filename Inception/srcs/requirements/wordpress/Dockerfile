# Pulling the minimal image
FROM debian:buster

# Installing requirements :: wordpress, php, mariadb-client
RUN apt-get -yq update && apt-get -yq install vim 
RUN apt-get install -yq curl 
RUN apt-get install -yq wget
RUN apt-get install php7.3-cli php7.3-fpm php7.3-mysql php7.3-json php7.3-opcache \
                    php7.3-mbstring php7.3-xml php7.3-cgi php-pear php7.3-zip \
                    php-net-socket php7.3-common php7.3-gd php7.3-curl \
                    php-xml-util php7.3-gettext php7.3-bcmath -yq
RUN apt-get install -yq mariadb-client
RUN apt-get install gettext-base

# Copying entrypoint from tools
COPY /tools/wordpress-entrypoint.sh /usr/bin/

# Get wordpress latest version
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz
RUN rm latest.tar.gz

# Copying wp-config.php from conf
COPY conf/wp-config.php .

# Installing wp-cli : https://wp-cli.org/
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

# Running wordpress and php-fm
ENTRYPOINT ["bash", "/usr/bin/wordpress-entrypoint.sh"]
