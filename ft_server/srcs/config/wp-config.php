<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d’installation. Vous n’avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en « wp-config.php » et remplir les
 * valeurs.
 *
 * Ce fichier contient les réglages de configuration suivants :
 *
 * Réglages MySQL
 * Préfixe de table
 * Clés secrètes
 * Langue utilisée
 * ABSPATH
 *
 * @link https://fr.wordpress.org/support/article/editing-wp-config-php/.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'wordpress' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', 'wordpress' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', 'password' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'localhost' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/**
 * Type de collation de la base de données.
 * N’y touchez que si vous savez ce que vous faites.
 */
define( 'DB_COLLATE', '' );

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clés secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '}hj=bv_^zlozkTjCLvO2{Mgw!w wO}.yH7}Nk50Pa#{1LKOTUejhdm3<!)b!vKXo' );
define( 'SECURE_AUTH_KEY',  '?b`fTKCOQ UY)M0%%}qj_kdr4}#1TbzA84_&I,)|{NqkKhr42S) /Wg7KGh!R=pt' );
define( 'LOGGED_IN_KEY',    'ow~ya/(-z78VcJ;r3L-@Pu+IHr?LS%wvtenzE8AT>hLz>pU(*~C*E1vgVe`NKgZq' );
define( 'NONCE_KEY',        '6`h3IUzhgOgZ_p6w2xL*OwOG1*=*-W8MM9#Hb &,0Wt=2m]uf|`jR/k[!lUj5g02' );
define( 'AUTH_SALT',        '+`:1_NSgn|T?9{PP9wJIR64>@=JDigyC:+l>,<!O$}v:a<P1z6Z]f OwH=:$&wLK' );
define( 'SECURE_AUTH_SALT', 'uX`k}Sg_$)qZ?)L%v90G}AAB,6z0sT63E*c%D}w6=N(kv_GMjW D68+B%4XmfnNw' );
define( 'LOGGED_IN_SALT',   ')wSn4pd .;Ve0LU*%Ml0r#axxx7K#`YT1ly^2{ZrM7pjOsx:8pt%(pagU9n<?1!x' );
define( 'NONCE_SALT',       '}$b!jgL~I3yH[o#Vp+|m]~XVR/Iri0{OsxB[/FE/j6qhy46&xd8^ZL,Lbi^e}%/^' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortement recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://fr.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( ! defined( 'ABSPATH' ) )
  define( 'ABSPATH', dirname( __FILE__ ) . '/' );

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once( ABSPATH . 'wp-settings.php' );
