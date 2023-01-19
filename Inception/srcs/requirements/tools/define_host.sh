# To make ngnix site enable to access by DOMAIN_NAME, the localhost address should receive
# new hostnames in etc/hosts to be accessed,
    
# Removing extra 42.fr lines
sudo sed -i '/42.fr/d' /etc/hosts

# Getting DOMAIN_NAME from .env

DOMAIN_ADDRESS="$(sudo cat ../../.env | grep "DOMAIN_NAME=$SUDO_USER" | sed s/DOMAIN_NAME=//g)"

# Appending to /etc/hosts
echo "127.0.0.1 $DOMAIN_ADDRESS" >> /etc/hosts
echo "127.0.0.1 www.$DOMAIN_ADDRESS" >> /etc/hosts
echo "127.0.0.1 https://www.$DOMAIN_ADDRESS" >> /etc/hosts
