@@ -48,6 +48,7 @@
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */
@@ -65,7 +66,6 @@ int main(void)
{
  /* USER CODE BEGIN 1 */
	//GPIO_PinState moja_tipka;

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/
@@ -97,11 +97,13 @@ int main(void)
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Stemi ukazi poskrbimo, da modra ledica utripa.

	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	HAL_Delay(500);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);
	HAL_Delay(500);


  }
  /* USER CODE END 3 */
}
@@ -156,41 +158,38 @@ static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
 /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LD4_Pin|LD3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
/*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LD4_Pin LD3_Pin */
/*Configure GPIO pins : LD4_Pin LD3_Pin */
  GPIO_InitStruct.Pin = LD4_Pin|LD3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
/* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}

/* USER CODE BEGIN 4 */
// S to funkcijo poskrbimo da se ledica prižge in ugasne s modrim gumbom.
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin_0)
{

	UNUSED (GPIO_Pin_0);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);
	for(uint32_t i=0; i<10000; i++);

}

/* USER CODE END 4 */
