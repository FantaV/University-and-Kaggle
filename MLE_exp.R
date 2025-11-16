# Carlo Villoresi
# Statistica & Big Data
# Corso di Inferenza Statistica
# Elaborato n°3

library(ggplot2)

# campione
data <- c(1.34, 3.56, 2.01)
data

# log-likelihood per la distribuzione esponenziale
log_like <- function(lambda) {
  sum(dexp(data, rate = lambda, log = TRUE))
}

# stima massima verosimiglianza usando optim
result <- optim(par = 0.1, function(l) -log_like(l), method = "Brent",  # Brent: esplora il range
                lower = 0.001, upper = 10)
mle_lambda <- result$par

cat("Stimatore di Massima Verosimiglianza per Lambda:", mle_lambda, "\n")

# creazione vettori per grafico
lambda_vals <- seq(0.001, 10, length.out = 500)
# sapply applica la funzione log_like a ciascun elemento di lambda_vals.
logL_vals <- sapply(lambda_vals, log_like)

df <- data.frame(lambda = lambda_vals, logL = logL_vals)

# plot
ggplot(df, aes(x = lambda, y = logL)) +
  geom_line(color = "blue", size = 1) +
  geom_vline(xintercept = mle_lambda, color = "red", linetype = "dashed") +
  geom_text(aes(x = mle_lambda, y = max(logL_vals), 
                label = paste0("MLE = ", round(mle_lambda, 3))),
            color = "red", vjust = -0.5, hjust = - 0.1) +
  labs(title = "Log-verosimiglianza per la distribuzione esponenziale",
       x = expression(lambda),
       y = "Log-Likelihood") +
  theme(
    panel.background = element_rect(fill = "lightgray", color = NA) # 'color = NA' rimuove il bordo
  )
  
