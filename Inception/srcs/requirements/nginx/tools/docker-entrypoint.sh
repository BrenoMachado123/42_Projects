# Create ssl folder
mkdir -p /etc/nginx/ssl
chmod 700 /etc/nginx/ssl/

# Set DOMAIN_NAME from .env
sed -ie s/'$DOMAIN_NAME'/$DOMAIN_NAME/g /etc/nginx/conf.d/wordpress.conf

# Create ssl certificate
openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/ssl_certificate.crt \
        -keyout /etc/nginx/ssl/ssl_certificate.key \
        -subj "/C=PO/ST=Portugal/L=Lisbon/O=42School/OU=42Lisboa/CN=bmachado.42.fr";

#unlink /etc/nginx/sites-enabled/default
#ln -s /etc/nginx/sites-available/default_page.conf /etc/nginx/sites-enabled/

# Disable gzip to enable SSH
sed -ie 's/gzip on;/gzip off;/g' /etc/nginx/nginx.conf

# Run ngnix container
nginx -g "daemon off;"