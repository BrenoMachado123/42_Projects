# References:
# https://www.ibm.com/docs/en/api-connect/10.0.1.x?topic=overview-generating-self-signed-certificate-using-openssl
# https://linuxize.com/post/creating-a-self-signed-ssl-certificate/


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

# Disable gzip to enable SSH: 
sed -ie 's/gzip on;/gzip off;/g' /etc/nginx/nginx.conf

# Run ngnix container
nginx -g "daemon off;"