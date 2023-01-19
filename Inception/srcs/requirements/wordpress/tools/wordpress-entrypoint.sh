#!/bin/bash

# References:
# https://www.howtoforge.com/tutorial/dockerizing-wordpress-with-nginx-and-php-fpm/
# https://stackoverflow.com/questions/42720618/docker-nginx-stopped-emerg-11-host-not-found-in-upstream
# https://www.hostinger.com/tutorials/run-docker-wordpress
# https://www.php.net/manual/en/install.fpm.php
# https://computingforgeeks.com/how-to-install-php-7-3-on-debian-9-debian-8/


# Creating /run/php to fix error at php-fm installation:
# https://itecnote.com/tecnote/php-unable-to-bind-listening-socket-for-address-php-fpm/
mkdir /run/php/

# Copying installed wordpress to var/www/html in order to enable it at ngnix server
# If wp-config.php already exists, there is no reason to do this again.
if [ ! -f var/www/html/wp-config.php ]
then
	cp -r wordpress/* var/www/html/
	rm -rf wordpress
	sed -i "s/MYSQL_DATABASE/$MYSQL_DATABASE/g" wp-config.php
	sed -i "s/MYSQL_PASSWORD/$MYSQL_PASSWORD/g" wp-config.php
	sed -i "s/MYSQL_USER/$MYSQL_USER/g" wp-config.php
	mv wp-config.php var/www/html
	rm var/www/html/wp-config-sample.php
else
	echo "wp-config.php already defined"
fi

sed -ie 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g' \
/etc/php/7.3/fpm/pool.d/www.conf

exec "$@"