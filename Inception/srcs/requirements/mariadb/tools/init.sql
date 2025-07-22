-- Create database
CREATE DATABASE IF NOT EXISTS `${DB_NAME}`;

-- Create user with proper quote handling
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_USERPWD}';

-- Grant privileges
GRANT ALL PRIVILEGES ON `${DB_NAME}`.* TO '${DB_USER}'@'%';

-- Update root password
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOTPWD}';

-- Apply changes
FLUSH PRIVILEGES;