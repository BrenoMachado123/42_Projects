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

# Copying installed wordpress content to var/www/html in order to enable it at ngnix server
# Also assign the enviroment variables inside wp-config.php
# If wp-config.php already exists, there is no reason to copy wordpress files again.
if [ ! -f var/www/html/wp-config.php ]
then
	cp -r wordpress/* var/www/html/
	rm -rf wordpress
	envsubst < wp-config.php > wp_config_env.php
	mv	wp_config_env.php var/www/html/
	mv	var/www/html/wp_config_env.php wp_config.php
	rm var/www/html/wp-config-sample.php
else
	echo "wordpress already moved"
fi

# Making php-fm listen to port 9000.
sed -ie 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g' \
/etc/php/7.3/fpm/pool.d/www.conf

exec "$@"