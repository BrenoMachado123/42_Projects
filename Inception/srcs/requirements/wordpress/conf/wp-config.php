<?php                                                                                                                                                  
/**                                                                                                                                                    
 * The base configuration for WordPress                                    
 *                                                                         
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.                                                 
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'MYSQL_DATABASE');

/** Database username */
define( 'DB_USER', 'MYSQL_USER'); 

/** Database password */
define( 'DB_PASSWORD', 'MYSQL_PASSWORD');

/** Database hostname */
define( 'DB_HOST', 'mariadb');

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+                                                                                                                                        [38/1870]
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'A;09( di6-H{aj=^_?>uj/kSxk9vaMS)Jux:fgyeph,jDj*Af-M]TL_E/~wU|:IN');
define('SECURE_AUTH_KEY',  'j2a]br@R,7N)}u~(t@>hhL+xvTQkAB$BMLk+V%>+)/dG*Q$t8272(G+hn&Q#||gN');
define('LOGGED_IN_KEY',    '_L6kbtu5o<z@rR1VI`^U*k/KexC2EDnGF-3+lR/$j,|q3]!7:gOKS3q+R:Wrf%,*');
define('NONCE_KEY',        '4v)3AQ=zKStNAroV;!;P,!=-NyWS+5.C|g8!LvKq_mgYqfGdG|;eK5>&iLUns;ex');
define('AUTH_SALT',        'oY1MTvj|YK-K2EP7{8-X}=1-sE3;- pQ0sf~[LVqo|&~V-/A9Ap*gMR;6-l6SgK_');
define('SECURE_AUTH_SALT', 'I}/H`[ZT|TgRq!J^y@[De.7/mW<NcI(+nM*K2(eeT_.?9vIo4VsY^{E%dm~!b|34');
define('LOGGED_IN_SALT',   '& )cV+&xURYa$zmW~e,z,I8;MgE!govr7&z_35-c-%Cog:FQUTSm;rYFSxd+7CU ');
define('NONCE_SALT',       '0$>Y!Fr.`ezqb(s2CZ]~L^h7)8Gx#%p*9Pmebq=,v,DNft}gH}h;--q?2tMx~@kE');

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development. 
 * It is strongly recommended that plugin and theme developers use WP_DEBUG 
 * in their development environments. 
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';