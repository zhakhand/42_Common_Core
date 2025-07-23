all:
	@echo "📁 Creating data directories..."
	@mkdir -p ~/data/mariadb ~/data/wordpress
	@echo "🐳 Building and starting containers (this may take a moment)..."
	@docker compose -f srcs/docker-compose.yml up -d --build > /dev/null 2>&1
	@echo "🎉 All containers built and running!"
	@echo ""
	@echo "Services status:"
	@docker compose -f srcs/docker-compose.yml ps --format "table {{.Name}}\t{{.Status}}\t{{.Ports}}"

down:
	@echo "🛑 Stopping containers..."
	@docker compose -f srcs/docker-compose.yml down -v > /dev/null 2>&1
	@echo "✅ Containers stopped"

clean: down
	@echo "🧹 Cleaning Docker system..."
	@docker system prune -af > /dev/null 2>&1
	@docker volume prune -f > /dev/null 2>&1
	@echo "✅ Docker system cleaned"

fclean: clean
	@echo "🗑️  Removing data directories..."
	@sudo rm -rf ${HOME}/data/wordpress > /dev/null 2>&1 || true
	@sudo rm -rf ${HOME}/data/mariadb > /dev/null 2>&1 || true
	@echo "✅ Data directories removed"

re: fclean all

.PHONY: all down clean fclean re