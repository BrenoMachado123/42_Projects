#!/bin/sh

mkdir /run/php/

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